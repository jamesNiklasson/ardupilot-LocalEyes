#include "AP_LocalEyesLUA.h"

AP_LocalEyesLUA *AP_LocalEyesLUA::_singleton;

uint32_t AP_LocalEyesLUA::customMillis() {
    return AP_HAL::millis();
}