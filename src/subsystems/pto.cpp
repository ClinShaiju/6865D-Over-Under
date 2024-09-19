#include "main.h"

bool ptoOn = false;
pros::ADIDigitalOut pto(PORT_ADI_PTO, ptoOn);

void runPtoToggle(int millis) {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X) && millis < 30000) {
        if (!ptoOn) {
            engagePTO();
            ptoOn = true;
        }
        else {
            disengagePTO();
            ptoOn = false;
        }
    }
}

void engagePTO() {
    pto.set_value(false);
    ptoOn = false;
}

void disengagePTO() {
    pto.set_value(true);
    ptoOn = true;
}