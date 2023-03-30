#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_RangeFinder/AP_RangeFinder.h>
#include <AP_Vehicle/AP_Vehicle.h>
#include <AP_AHRS/AP_AHRS.h>
#include <GCS_MAVLink/GCS.h>

class AP_LocalEyes {
public:
    AP_LocalEyes() {
        if (!_singleton) {
            dropReady = false;
            _singleton = this;
        } else {
            AP_HAL::panic("Too many AP_LocalEyes instances");
        }
    }

    static AP_LocalEyes *get_singleton() {
        if (!_singleton) {
            new AP_LocalEyes();
        }
        return _singleton;
    }

    //allows use of HAL millis function in LUA scripts
    uint32_t customMillis();

    //allows direct use of height as meassured by LIDAR
    float lidarHeight();

    //distance to the next waypoint in m
    float waypointDist();

    //current NED speed in m/s
    float nedSpeed();

    //set or clear the GPS drop ready flag
    void setDropReadyFlag(bool dropReady);

    //get the GPS drop ready flag
    bool isDropReady();

private:
    static AP_LocalEyes *_singleton;
    bool dropReady;
};