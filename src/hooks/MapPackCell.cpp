#include "../ProgressBar.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/MapPackCell.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIMapPackCell, MapPackCell) {
    struct Fields {
        ProgressBar* m_apiProgressBar = nullptr;
    };

    void loadFromMapPack(GJMapPack * p0) {
        MapPackCell::loadFromMapPack(p0);

        if (auto bar = m_mainLayer->getChildByIndex(2)) {
            m_fields->m_apiProgressBar = ProgressBar::create();
            m_fields->m_apiProgressBar->setID("pack-progress-bar"_spr);
            m_fields->m_apiProgressBar->setStyle(ProgressBarStyle::Solid);
            m_fields->m_apiProgressBar->setAnchorPoint(bar->getAnchorPoint());
            m_fields->m_apiProgressBar->setPosition(bar->getPosition());
            m_fields->m_apiProgressBar->setZOrder(bar->getZOrder());
            m_fields->m_apiProgressBar->setScaleX(bar->getScaleX());
            m_fields->m_apiProgressBar->setScaleY(bar->getScaleY());

            if (auto spr = bar->getChildByType<CCSprite*>(0)) m_fields->m_apiProgressBar->setFillColor(spr->getColor());

            m_fields->m_apiProgressBar->updateProgress((static_cast<float>(m_mapPack->completedMaps()) / 3.f) * 100.f);

            bar->setID("pack-progress-bar");
            bar->setVisible(false);

            m_mainLayer->addChild(m_fields->m_apiProgressBar);
        } else {
            log::error("Couldn't find progress bar for map pack cell");
        };
    }
};