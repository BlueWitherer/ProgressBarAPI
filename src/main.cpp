#include <cmath>

#include "../incl/ProgressBar.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto testb = ProgressBar::create();
        testb->setID("my-bar"_spr);
        testb->updateProgress(65.f);
        testb->setPosition({ 100.f, 100.f });
        testb->setStyle(ProgressBarStyle::Level);
        testb->showProgressLabel(true);

        addChild(testb);

        return true;
    };
};

class $modify(ProgressAPIPlayLayer, PlayLayer) {
    struct Fields {
        bool m_isBarVisible = false;

        ProgressBar* m_apiProgressBar = nullptr;
    };

    void setupHasCompleted() {
        PlayLayer::setupHasCompleted();

        m_fields->m_isBarVisible = m_progressBar->isVisible();

        log::info("Switching progress bar to API version");

        // assign the new progress bar
        m_fields->m_apiProgressBar = ProgressBar::create();
        m_fields->m_apiProgressBar->setID("progress-bar"_spr);
        m_fields->m_apiProgressBar->setAnchorPoint({ 0.5, 0.5 });
        m_fields->m_apiProgressBar->setPosition({ getScaledContentWidth() / 2.f, getScaledContentHeight() - 8.f });
        m_fields->m_apiProgressBar->setProgressBarFillColor(m_progressFill->getColor());
        m_fields->m_apiProgressBar->setVisible(m_fields->m_isBarVisible);

        addChild(m_fields->m_apiProgressBar);

        if (m_progressBar->isVisible()) m_progressBar->setVisible(false); // hide og bar
    };

    void updateProgressbar() {
        PlayLayer::updateProgressbar();

        auto percent = getCurrentPercent();

        if (m_fields->m_apiProgressBar) m_fields->m_apiProgressBar->updateProgress(percent);
    };

    void toggleProgressbar() {
        PlayLayer::toggleProgressbar();

        m_fields->m_isBarVisible = !m_fields->m_isBarVisible;

        if (m_fields->m_apiProgressBar) m_fields->m_apiProgressBar->setVisible(m_fields->m_isBarVisible);
        if (m_progressBar->isVisible()) m_progressBar->setVisible(false);
    };
};