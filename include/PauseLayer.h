#include <ProgressBar.hpp>

#include <Geode/Geode.hpp>

#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

namespace progressbarapi {
    class $modify(ProgressAPIPauseLayer, PauseLayer) {
        struct Fields {
            GJGameLevel* level = nullptr;
            ProgressBar* m_apiProgressBar = nullptr;
        };

        void customSetup() {
            PauseLayer::customSetup();

            if (auto playLayer = PlayLayer::get()) m_fields->level = playLayer->m_level;

            if (auto bar = getChildByID("normal-progress-bar")) {
                m_fields->m_apiProgressBar = ProgressBar::create();
                m_fields->m_apiProgressBar->setID("normal-progress-bar"_spr);
                m_fields->m_apiProgressBar->setStyle(ProgressBarStyle::Solid);
                m_fields->m_apiProgressBar->setAnchorPoint(bar->getAnchorPoint());
                m_fields->m_apiProgressBar->setPosition(bar->getPosition());
                m_fields->m_apiProgressBar->setZOrder(bar->getZOrder());
                m_fields->m_apiProgressBar->setScale(bar->getScale());
                m_fields->m_apiProgressBar->showProgressLabel(true);

                if (auto spr = bar->getChildByType<CCSprite*>(0)) m_fields->m_apiProgressBar->setFillColor(spr->getColor());
                if (auto label = getChildByID("normal-progress-label")) label->setVisible(false);

                if (m_fields->level) m_fields->m_apiProgressBar->updateProgress(static_cast<float>(m_fields->level->m_normalPercent));

                bar->setVisible(false);

                addChild(m_fields->m_apiProgressBar);
            } else {
                log::error("Couldn't find progress bar for map pack cell");
            };

            if (auto bar = getChildByID("practice-progress-bar")) {
                m_fields->m_apiProgressBar = ProgressBar::create();
                m_fields->m_apiProgressBar->setID("normal-progress-bar"_spr);
                m_fields->m_apiProgressBar->setStyle(ProgressBarStyle::Solid);
                m_fields->m_apiProgressBar->setAnchorPoint(bar->getAnchorPoint());
                m_fields->m_apiProgressBar->setPosition(bar->getPosition());
                m_fields->m_apiProgressBar->setZOrder(bar->getZOrder());
                m_fields->m_apiProgressBar->setScale(bar->getScale());
                m_fields->m_apiProgressBar->showProgressLabel(true);

                if (auto spr = bar->getChildByType<CCSprite*>(0)) m_fields->m_apiProgressBar->setFillColor(spr->getColor());
                if (auto label = getChildByID("practice-progress-label")) label->setVisible(false);

                if (m_fields->level) m_fields->m_apiProgressBar->updateProgress(static_cast<float>(m_fields->level->m_practicePercent));

                bar->setVisible(false);

                addChild(m_fields->m_apiProgressBar);
            } else {
                log::error("Couldn't find progress bar for map pack cell");
            };
        };
    };
};