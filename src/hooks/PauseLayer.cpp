#include "../ProgressBar.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIPauseLayer, PauseLayer) {
    struct Fields {
        GJGameLevel* level = nullptr;

        ProgressBar* m_apiNormalProgressBar = nullptr;
        ProgressBar* m_apiPracticeProgressBar = nullptr;
    };

    void customSetup() {
        PauseLayer::customSetup();

        if (auto playLayer = PlayLayer::get()) m_fields->level = playLayer->m_level;

        if (auto bar = getChildByID("normal-progress-bar")) {
            m_fields->m_apiNormalProgressBar = ProgressBar::create();
            m_fields->m_apiNormalProgressBar->setID("normal-progress-bar"_spr);
            m_fields->m_apiNormalProgressBar->setStyle(ProgressBarStyle::Solid);
            m_fields->m_apiNormalProgressBar->setAnchorPoint(bar->getAnchorPoint());
            m_fields->m_apiNormalProgressBar->setPosition(bar->getPosition());
            m_fields->m_apiNormalProgressBar->setZOrder(bar->getZOrder());
            m_fields->m_apiNormalProgressBar->setScale(bar->getScale());
            m_fields->m_apiNormalProgressBar->showProgressLabel(true);

            if (auto spr = bar->getChildByType<CCSprite*>(0)) m_fields->m_apiNormalProgressBar->setFillColor(spr->getColor());
            if (auto label = getChildByID("normal-progress-label")) label->setVisible(false);

            if (m_fields->level) m_fields->m_apiNormalProgressBar->updateProgress(static_cast<float>(m_fields->level->m_normalPercent));

            bar->setVisible(false);

            addChild(m_fields->m_apiNormalProgressBar);
        } else {
            log::error("Couldn't find progress bar for map pack cell");
        };

        if (auto bar = getChildByID("practice-progress-bar")) {
            m_fields->m_apiPracticeProgressBar = ProgressBar::create();
            m_fields->m_apiPracticeProgressBar->setID("normal-progress-bar"_spr);
            m_fields->m_apiPracticeProgressBar->setStyle(ProgressBarStyle::Solid);
            m_fields->m_apiPracticeProgressBar->setAnchorPoint(bar->getAnchorPoint());
            m_fields->m_apiPracticeProgressBar->setPosition(bar->getPosition());
            m_fields->m_apiPracticeProgressBar->setZOrder(bar->getZOrder());
            m_fields->m_apiPracticeProgressBar->setScale(bar->getScale());
            m_fields->m_apiPracticeProgressBar->showProgressLabel(true);

            if (auto spr = bar->getChildByType<CCSprite*>(0)) m_fields->m_apiPracticeProgressBar->setFillColor(spr->getColor());
            if (auto label = getChildByID("practice-progress-label")) label->setVisible(false);

            if (m_fields->level) m_fields->m_apiPracticeProgressBar->updateProgress(static_cast<float>(m_fields->level->m_practicePercent));

            bar->setVisible(false);

            addChild(m_fields->m_apiPracticeProgressBar);
        } else {
            log::error("Couldn't find progress bar for map pack cell");
        };
    };
};