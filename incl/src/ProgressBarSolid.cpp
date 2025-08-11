#include "../ProgressBarSolid.hpp"

#include <ProgressBar.hpp>

#include <fmt/core.h>

#include <Geode/Geode.hpp>

using namespace geode::prelude;

bool ProgressBarSolid::init() {
    if (CCNode::init()) {
        setID("bar-solid"_spr);

        m_progressBar = CCSprite::create("GJ_progressBar_001.png");
        m_progressBar->setID("progress-bar");
        m_progressBar->setAnchorPoint({ 0.5, 0.5 });
        m_progressBar->setPosition({ m_progressBar->getScaledContentWidth() / 2.f, m_progressBar->getScaledContentHeight() / 2.f });
        m_progressBar->setColor({ 0, 0, 0 });
        m_progressBar->setOpacity(125);

        setScaledContentSize(m_progressBar->getScaledContentSize());

        m_progressBarFill = CCSprite::create("GJ_progressBar_001.png");
        m_progressBarFill->setID("bar-fill");
        m_progressBarFill->setScale(0.992f);
        m_progressBarFill->setScaleY(0.86f);
        m_progressBarFill->setAnchorPoint({ 0, 0.5 });
        m_progressBarFill->setPosition({ 1.36f, m_progressBar->getScaledContentHeight() / 2.f });
        m_progressBarFill->setColor({ 255, 255, 255 });
        m_progressBarFill->setZOrder(1);

        m_progressBarFillMaxWidth = m_progressBar->getScaledContentWidth();
        m_progressBarFillMaxHeight = 20.f;

        updateBar(0.f);

        m_progressBar->addChild(m_progressBarFill);

        addChild(m_progressBar);

        m_progressPercentLabel = CCLabelBMFont::create("0%", "bigFont.fnt");
        m_progressPercentLabel->setID("percent-label");
        m_progressPercentLabel->setScale(0.5f);
        m_progressPercentLabel->setAnchorPoint({ 0.5, 0.5 });
        m_progressPercentLabel->setPosition({ getScaledContentWidth() / 2.f, getScaledContentHeight() / 2.f });
        m_progressPercentLabel->setZOrder(2);

        addChild(m_progressPercentLabel);

        return true;
    } else {
        return false;
    };
};

void ProgressBarSolid::updateBar(float value) {
    auto percentString = fmt::format("{}%", static_cast<int>(value));
    if (m_progressPercentLabel) m_progressPercentLabel->setCString(percentString.c_str());

    ProgressBar::updateBar(value);
};

ProgressBarSolid* ProgressBarSolid::create() {
    auto ret = new ProgressBarSolid();

    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    };

    CC_SAFE_DELETE(ret);
    return nullptr;
};