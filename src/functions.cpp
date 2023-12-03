#include "main.h"


//exponential drive
double returnExponential(int axisValue, int type, float t) {
    double percentage = axisValue;
    if (type == 1) {
        if (percentage > 0) {
            percentage = 1.2 * pow(1.035664, percentage) - 1.2 + 0.2 * percentage;
        } else {
            percentage = -percentage;

            percentage = 1.2 * pow(1.035664, percentage) - 1.2 + 0.2 * percentage;

            percentage = -percentage;
        }
        return percentage;
    }
    else if (type == 2) {
        return (exp(-(t/10)) + exp((std::abs(percentage)-127)/10) * (1-exp(-(t/10))))*percentage;
    }
    else if (type == 3) {
        return (exp((std::abs(percentage)-127)/1000))*percentage;
    }
    return 0;
}

int rightType, leftType;
float rightT, leftT;

void runDriveCurveTester() {
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) leftT-=.5;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) leftT+=.5;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) rightT+=.5;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) rightT-=.5;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) leftType-=1;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)) leftType+=1;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) rightType-=1;
    if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) rightType+=1;
}

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

float formatHeading(float heading) {
    int signum = sgn(heading);
    float output = std::abs(heading);

    while (output > 360) output -= 360;
    if (signum == -1) return 360 - output;
    return output;
}

