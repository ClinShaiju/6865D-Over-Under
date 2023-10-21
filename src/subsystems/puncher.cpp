#include "main.h"

pros::Motor puncher = pros::Motor(PORT_PUNCHER, pros::E_MOTOR_GEARSET_06, true);
bool puncherPressed = false;
bool puncherRunning = false;

void runPuncherToggle() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) {
        if (!puncherPressed) {
            if (!puncherRunning) {
                puncher.move_velocity(getVelocityOutput(puncher, 127));
                puncherRunning = true;
            }
            else {
                puncher = 0;
                puncherRunning = false;
            }
        }
        puncherPressed = true;
    } else {
        puncherPressed = false;
    }
}
