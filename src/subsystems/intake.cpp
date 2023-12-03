#include "main.h"

pros::Motor intake = pros::Motor(PORT_INTAKE, pros::E_MOTOR_GEARSET_18, true);

void runIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intake = 127;
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intake = -127;
    }
    else intake = 0;
}

void intakeIn() {
    intake = 127;
}

void intakeOut() {
    intake = -127;
}

void intakeStop() {
    intake = 0;
}