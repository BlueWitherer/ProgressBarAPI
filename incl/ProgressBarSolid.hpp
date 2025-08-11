#pragma once

#include <ProgressBar.hpp>

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class ProgressBarSolid : public ProgressBar {
protected:
    bool init() override;

public:
    // Create the custom progress bar
    static ProgressBarSolid* create();

    CCLabelBMFont* m_progressPercentLabel = nullptr; // The text label displaying the percentage

    /**
     * Update the fill of the bar and the percentage label
     *
     * @param value An integer from 0 to 100
     */
    void updateBar(float value) override;
};