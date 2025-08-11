#pragma once

#include "ProgressBar.hpp"

#include <Geode/Geode.hpp>

using namespace geode::prelude;

// Custom class for the Normal/Practice mode style progress bar
class ProgressBarSolid : public ProgressBar {
protected:
    bool init() override;

public:
    // Create a custom progress bar
    static ProgressBarSolid* create();

    CCLabelBMFont* m_progressPercentLabel = nullptr; // The text label displaying the percentage

    /**
     * Update the size of the fill of the bar and the percentage label
     *
     * @param value A float from 0 to 100
     */
    void updateBar(float value) override;
};