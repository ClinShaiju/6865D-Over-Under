#include "main.h"

pros::ADIDigitalOut wingLeft(PORT_ADI_WING_LEFT, false);
pros::ADIDigitalOut wingRight(PORT_ADI_WING_RIGHT, false);


void runWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        wingLeft.set_value(true);
        wingRight.set_value(true);
    } else {
        wingLeft.set_value(false);
        wingRight.set_value(false);
    }
}