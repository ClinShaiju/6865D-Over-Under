#include "main.h"

//exponential drive
double returnExponential(int axisValue) {
    double percentage = axisValue;
    if (percentage > 0) {
        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;
    }
    else {
        percentage = -percentage;

        percentage = 1.2*pow(1.043, percentage) - 1.2 + 0.2 * percentage;

        percentage = -percentage;
    }
    return percentage;
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