#pragma once

#include <AP_HAL/AP_HAL.h>

class AP_LocalEyesLUA {
public:
    AP_LocalEyesLUA();
    static AP_LocalEyesLUA *get_singleton();

    //allows use of HAL millis function in LUA scripts
    uint32_t customMillis();

private:
    static AP_LocalEyesLUA *_singleton;
};