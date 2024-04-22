#include "main.h"

pros::ADIDigitalOut frontWingLeft(PORT_ADI_FRONT_WING_LEFT, false);
pros::ADIDigitalOut frontWingRight(PORT_ADI_FRONT_WING_RIGHT, false);

pros::ADIDigitalOut backWingLeft(PORT_ADI_BACK_WING_LEFT, false);
pros::ADIDigitalOut backWingRight(PORT_ADI_BACK_WING_RIGHT, false);

void runFrontWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        frontWingLeft.set_value(true);
        frontWingRight.set_value(true);
    } else {
        frontWingLeft.set_value(false);
        frontWingRight.set_value(false);
    }
}

void frontWingsOut() {
    frontWingLeft.set_value(true);
    frontWingRight.set_value(true);
}

void frontWingsIn() {
    frontWingLeft.set_value(false);
    frontWingRight.set_value(false);
}

void frontLeftWingOut() {
    frontWingLeft.set_value(true);
}

void frontLeftWingIn() {
    frontWingLeft.set_value(false);
}

void frontRightWingOut() {
    frontWingRight.set_value(true);
}

void frontRightWingIn() {
    frontWingRight.set_value(false);
}

void runBackWings() {
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        backWingLeft.set_value(true);
        backWingRight.set_value(true);
    } else {
        backWingLeft.set_value(false);
        backWingRight.set_value(false);
    }
}

void backWingsOut() {
    backWingLeft.set_value(true);
    backWingRight.set_value(true);
}

void backWingsIn() {
    backWingLeft.set_value(false);
    backWingRight.set_value(false);
}

void backLeftWingOut() {
    backWingLeft.set_value(true);
}

void backLeftWingIn() {
    backWingLeft.set_value(false);
}

void backRightWingOut() {
    backWingRight.set_value(true);
}

void backRightWingIn() {
    backWingRight.set_value(false);
}