#pragma once

#include <Geode/Geode.hpp>

#include <Geode/utils/terminate.hpp>

using namespace geode::prelude;

class ProgressBar : public CCNode {
protected:
    Mod* m_mod = getMod(); // Progress Bar API

    Ref<CCSprite> m_progressBar = nullptr; // Progress bar outline
    CCSprite* m_progressBarFill = nullptr; // Progress bar fill

    bool init() override;

public:
    // Create the custom progress bar
    static ProgressBar* create();

    float m_progress = 0.f;

    /**
     * Update the fill of the bar
     *
     * @param value An integer from 0 to 100
     * @param time Optional animation time
     */
    void updateBar(float value, float time = 0.f);

    /**
     * Set the color of the fill of the bar
     *
     * @param color RGB color object
     */
    void setBarColor(ccColor3B color);

    /**
     * Get the current progress of the bar
     */
    float getProgress();
};