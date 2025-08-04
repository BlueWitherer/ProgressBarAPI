#include "../ProgressBar.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool ProgressBar::init() {
    if (CCNode::init()) {
        setID("bar"_spr);

        ccColor3B defaultColor = { 255, 255, 255 };
        auto forcePlayer = m_mod->getSettingValue<bool>("force-color");

        if (auto gm = GameManager::sharedState()) forcePlayer ? defaultColor = gm->colorForIdx(gm->m_playerColor2.value()) : defaultColor;

        m_progressBar = CCSprite::create("slidergroove2.png");
        m_progressBar->setID("progress-bar");
        m_progressBar->setPosition({ m_progressBar->getScaledContentWidth() / 2.f, m_progressBar->getScaledContentHeight() / 2.f });
        m_progressBar->setAnchorPoint({ 0.5, 0.5 });
        m_progressBar->setZOrder(501);

        setScaledContentSize(m_progressBar->getScaledContentSize());

        m_progressBarFill = CCSprite::create("sliderBar2.png");
        m_progressBarFill->setID("bar-fill");
        m_progressBarFill->setAnchorPoint({ 0, 0.5 });
        m_progressBarFill->setPosition({ 2.f, m_progressBar->getScaledContentHeight() / 2.f });
        m_progressBarFill->setTextureRect({ 0, 0, 0, 8 });
        m_progressBarFill->setZOrder(-1);

        m_progressBar->addChild(m_progressBarFill);

        addChild(m_progressBar);

        return true;
    } else {
        return false;
    };
};

void ProgressBar::updateBar(float value, float time) {
    if (value <= 100.f && value >= 0.f) {
        if (m_progressBar && m_progressBarFill) {
            float max = m_progressBar->getScaledContentWidth() - 4.f;
            float width = max * (value / 100.f);

            log::debug("Updating progress bar fill size to {}", width);

            m_progressBarFill->setTextureRect({ 0, 0, width, 8 });
        };
    } else {
        log::error("Cannot set fill to {}%", value);
    };
};

void ProgressBar::setBarColor(ccColor3B color) {
    if (auto gm = GameManager::sharedState()) {
        auto forcePlayer = m_mod->getSettingValue<bool>("force-color");

        if (m_progressBarFill) m_progressBarFill->setColor(forcePlayer ? color : gm->colorForIdx(gm->getPlayerColor2()));
    };
};

ProgressBar* ProgressBar::create() {
    auto ret = new ProgressBar();

    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};