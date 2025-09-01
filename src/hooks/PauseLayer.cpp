#include "../../incl/ProgressBar.hpp"

#include <Geode/Geode.hpp>

#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(ProgressAPIPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();


    };
};