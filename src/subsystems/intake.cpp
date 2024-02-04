#include "main.h"

pros::Motor intake = pros::Motor(PORT_INTAKE, pros::E_MOTOR_GEARSET_18, true);
pros::ADIDigitalOut intakeHolder(PORT_ADI_INTAKE_HOLDER, true);

void dropIntake() {
    intakeHolder.set_value(false);
}

void runIntake() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) intakeIn();
    else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) intakeOut();
    else intakeStop();
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