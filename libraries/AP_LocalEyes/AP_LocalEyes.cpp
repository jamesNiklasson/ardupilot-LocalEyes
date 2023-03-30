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

float AP_LocalEyes::waypointDist() {
    float distance;
    if (AP_Vehicle::get_singleton()->get_wp_distance_m(distance)) return distance;
    return 0;
}

float AP_LocalEyes::nedSpeed() {
    Vector3f ned_velocity;
    if (AP_AHRS::get_singleton()->get_velocity_NED(ned_velocity)) return ned_velocity.length();
    return 0;
}

void AP_LocalEyes::setDropReadyFlag(bool dropReadyFlag) {
    this -> dropReady = dropReadyFlag;
    if (dropReadyFlag) {
        GCS::get_singleton() -> send_text(MAV_SEVERITY_INFO, "Drop ready flag set!");
    } else {
        GCS::get_singleton() -> send_text(MAV_SEVERITY_INFO, "Drop ready flag cleared!");
    }
}

bool AP_LocalEyes::isDropReady() {
    return this -> dropReady;
}