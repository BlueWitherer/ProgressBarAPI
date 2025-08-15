#include <cmath>

#include <ProgressBar.hpp>
#include <ProgressBarSolid.hpp>

#include <Geode/Geode.hpp>

#include <Geode/modify/PlayLayer.hpp>

#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIPlayLayer, PlayLayer) {
    struct Fields {
        ProgressBar* m_apiProgressBar = nullptr;
        ProgressBarSolid* m_apiProgressBarSolid = nullptr;
    };

    void setupHasCompleted() {
        PlayLayer::setupHasCompleted();

        if (getMod()->getSettingValue<bool>("level")) {
            log::info("Switching progress bar to API version");

            if (auto ogProgressBar = getChildByID("progress-bar")) {
                log::debug("Replacing original progress bar");

                // create a menu to appear on top which will just have a layout really
                if (auto topMenu = CCMenu::create()) {
                    topMenu->setID("menu"_spr);
                    topMenu->setScaledContentSize({ 0.f, 16.f });
                    topMenu->setPosition({ getScaledContentWidth() / 2.f, getScaledContentHeight() - 8.f });
                    topMenu->setZOrder(101);

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
                    m_fields->m_apiProgressBar->setProgressBarFillColor({ 100, 255, 125 });
                    m_fields->m_apiProgressBar->setVisible(ogProgressBar->isVisible());

                    topMenu->addChild(m_fields->m_apiProgressBar);

                    // assign the new progress bar
                    m_fields->m_apiProgressBarSolid = ProgressBarSolid::create();
                    m_fields->m_apiProgressBarSolid->setID("my-solid-progress-bar"_spr);
                    m_fields->m_apiProgressBarSolid->setProgressBarFillColor({ 100, 255, 125 });
                    m_fields->m_apiProgressBarSolid->setVisible(ogProgressBar->isVisible());

                    topMenu->addChild(m_fields->m_apiProgressBarSolid);

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
    };

    void updateProgressbar() {
        PlayLayer::updateProgressbar();

        auto percent = getCurrentPercent();
        log::debug("Updating API progress bar to {}%", percent);

        if (m_fields->m_apiProgressBar) m_fields->m_apiProgressBar->updateProgress(percent);
        if (m_fields->m_apiProgressBarSolid) m_fields->m_apiProgressBarSolid->updateProgress(percent);
    };

    void toggleProgressbar() {
        PlayLayer::toggleProgressbar();

        auto isVisible = m_progressBar->isVisible();

        if (m_fields->m_apiProgressBar) m_fields->m_apiProgressBar->setVisible(isVisible);
        if (m_fields->m_apiProgressBarSolid) m_fields->m_apiProgressBarSolid->setVisible(isVisible);
    };
};