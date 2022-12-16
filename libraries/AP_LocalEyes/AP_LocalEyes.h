#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_RangeFinder/AP_RangeFinder.h>

class AP_LocalEyes {
public:
    AP_LocalEyes() {
        if (!_singleton) {
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

private:
    static AP_LocalEyes *_singleton;
};