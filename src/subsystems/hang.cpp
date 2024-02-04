#include "main.h"

#include "main.h"

pros::ADIDigitalOut sideHang(PORT_ADI_SIDE_HANG, true);
bool isSideHangUp = false;

void runSideHangToggle() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
        if (!isSideHangUp) {
            engageSideHang();
        }
        else {
            disengageSideHang();
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
