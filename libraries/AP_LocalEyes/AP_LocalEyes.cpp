#include "AP_LocalEyes.h"

AP_LocalEyes *AP_LocalEyes::_singleton;

uint32_t AP_LocalEyes::customMillis() {
    return AP_HAL::millis();
}

float AP_LocalEyes::lidarHeight() {
    RangeFinder *rangeFinder = RangeFinder::get_singleton();
    if (rangeFinder) {
        return rangeFinder->distance_orient(ROTATION_PITCH_270);
    }
    return 0;
}