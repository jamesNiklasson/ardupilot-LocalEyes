#pragma once

#include <AP_HAL/AP_HAL.h>

class AP_LocalEyesLUA {
public:
    AP_LocalEyesLUA() {
        if (!_singleton) {
            _singleton = this;
        } else {
            AP_HAL::panic("Too many AP_LocalEyesLUA instances");
        }
    }

    static AP_LocalEyesLUA *get_singleton() {
        if (!_singleton) {
            new AP_LocalEyesLUA();
        }
        return _singleton;
    }

    //allows use of HAL millis function in LUA scripts
    uint32_t customMillis();

private:
    static AP_LocalEyesLUA *_singleton;
};