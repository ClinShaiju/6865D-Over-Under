#include "main.h"

#include "main.h"

pros::ADIDigitalOut sideHang(PORT_ADI_SIDE_HANG, false);
pros::ADIDigitalOut mainHang(PORT_ADI_MAIN_HANG, false);
bool isSideHangUp = true;
bool isMainHangUp = true;

void runSideHangToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        if (!isSideHangUp) {
            engageSideHang();
            isSideHangUp = true;
        }
        else {
            disengageSideHang();
            isSideHangUp = false;
        }
    }
}

void engageSideHang() {
    sideHang.set_value(false);
    isSideHangUp = false;
}

void disengageSideHang() {
    sideHang.set_value(true);
    isSideHangUp = true;
}

void runMainHangToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
        if (!isMainHangUp) {
            engageMainHang();
            isMainHangUp = true;
        }
        else {
            disengageMainHang();
            isMainHangUp = false;
        }
    }
}

void engageMainHang() {
    mainHang.set_value(false);
    isMainHangUp = false;
}

void disengageMainHang() {
    mainHang.set_value(true);
    isMainHangUp = true;
}
