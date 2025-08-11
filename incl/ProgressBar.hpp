#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

// Custom progress bar class
class ProgressBar : public CCNode {
protected:
    Ref<CCSprite> m_progressBar = nullptr; // Progress bar outline
    CCSprite* m_progressBarFill = nullptr; // Progress bar fill

    bool init() override;

public:
    // Create the custom progress bar
    static ProgressBar* create();

    float m_progress = 0.f; // Current progress bar fill

    float m_progressBarFillMaxWidth = 0.f; // Max width for the progress fill bar node
    float m_progressBarFillMaxHeight = 0.f; // Max height for the progress fill bar node

    /**
     * Set the color of the fill of the bar
     *
     * @param color RGB color object
     */
    void setBarColor(ccColor3B color);

    /**
     * Update the fill of the bar
     *
     * @param value An integer from 0 to 100
     */
    virtual void updateBar(float value);

    /**
     * Get the current progress of the bar
     */
    float getProgress();
};