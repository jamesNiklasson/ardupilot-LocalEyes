#include "AP_LocalEyesLUA.h"

AP_LocalEyesLUA *AP_LocalEyesLUA::_singleton;

AP_LocalEyesLUA::AP_LocalEyesLUA() {
    if (_singleton) {
        AP_HAL::panic("Too many AP_LocalEyesLUA instances");
    }
    _singleton = this;
}

AP_LocalEyesLUA *AP_LocalEyesLUA::get_singleton() {
    return AP_LocalEyesLUA::_singleton;
}

uint32_t AP_LocalEyesLUA::customMillis() {
    return AP_HAL::millis();
}