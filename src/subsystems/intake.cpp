#include "main.h"

pros::Motor intake = pros::Motor(5, pros::E_MOTOR_GEARSET_18, true);

void runIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        intake.move_velocity(getVelocityOutput(intake, 127));
    }
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) {
        intake.move_velocity(getVelocityOutput(intake, -127));
    }
    else intake = 0;
}