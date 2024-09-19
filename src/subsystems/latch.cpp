#include "main.h"

bool latchOn = false;
pros::ADIDigitalOut latch(PORT_ADI_LATCH, latchOn);

void runLatchToggle(int millis) {

    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B) && millis < 30000) {
        if (!latchOn) {
            engageLatch();
            latchOn = true;
        }
        else {
            disengageLatch();
            latchOn = false;
        }
    }
}

void engageLatch() {
    latch.set_value(false);
    latchOn = false;
}

void disengageLatch() {
    latch.set_value(true);
    latchOn = true;
}