#include <cmath>

#include <ProgressBar.hpp>

#include <Geode/Geode.hpp>

#include <Geode/modify/PlayLayer.hpp>

#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIPlayLayer, PlayLayer) {
    struct Fields {
        ProgressBar* m_apiProgressBar = nullptr;
    };

    bool init(GJGameLevel * level, bool useReplay, bool dontCreateObjects) {
        if (PlayLayer::init(level, useReplay, dontCreateObjects)) {
            if (getMod()->getSettingValue<bool>("level")) {
                log::info("Switching progress bar to API version");

                if (auto ogProgressBar = getChildByID("progress-bar")) {
                    log::debug("Replacing original progress bar");

                    // create a menu to appear on top which will just have a layout really
                    if (auto topMenu = CCMenu::create()) {
                        topMenu->setID("menu"_spr);
                        topMenu->setScaledContentSize({ 0.f, 16.f });
                        topMenu->setPosition({ getScaledContentWidth() / 2.f, getScaledContentHeight() - 8.f });

                        // the layout for the menu
                        auto topMenuLayout = RowLayout::create()
                            ->setGap(5.f)
                            ->setAutoScale(true)
                            ->setAutoGrowAxis(0.f)
                            ->setAxisAlignment(AxisAlignment::Center)
                            ->setCrossAxisAlignment(AxisAlignment::Center)
                            ->setCrossAxisLineAlignment(AxisAlignment::Center)
                            ->setAxisReverse(false);

                        topMenu->setLayout(topMenuLayout);

                        // assign the new progress bar
                        m_fields->m_apiProgressBar = ProgressBar::create();
                        m_fields->m_apiProgressBar->setID("my-progress-bar"_spr);
                        m_fields->m_apiProgressBar->setBarColor({ 100, 255, 125 });
                        m_fields->m_apiProgressBar->setZOrder(101);

                        topMenu->addChild(m_fields->m_apiProgressBar);

                        if (auto ogPercentLabel = getChildByID("percentage-label")) ogPercentLabel->setParent(topMenu); // try to move the percent label

                        topMenu->updateLayout(true);

                        addChild(topMenu);

                        ogProgressBar->setVisible(false); // hide og bar
                    } else {
                        log::error("Failed to create new progress bar");
                    };
                } else {
                    log::warn("No progress bar found to replace");
                };
            } else {
                log::debug("Keeping vanilla progress bar");
            };

            return true;
        } else {
            return false;
        };
    };

    void updateProgressbar() {
        if (m_fields->m_apiProgressBar) {
            auto percent = getCurrentPercent();
            log::debug("Updating API progress bar to {}%", percent);

            m_fields->m_apiProgressBar->updateBar(percent);
        };

        PlayLayer::updateProgressbar();
    };

    void toggleProgressbar() {
        if (m_fields->m_apiProgressBar) {
            m_fields->m_apiProgressBar->setVisible(!m_fields->m_apiProgressBar->isVisible());
            m_fields->m_apiProgressBar->setZOrder(101);
        } else {
            log::error("Couldn't toggle API progress bar");
        };

        PlayLayer::toggleProgressbar();
    };
};