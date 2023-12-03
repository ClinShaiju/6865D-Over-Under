#include "main.h"

//exponential drive
double returnExponential(int axisValue, int, float);

extern float rightT, leftT;
extern int rightType, leftType;
void runDriveCurveTest();

template <typename T> int sgn(T val);

float formatHeading(float heading);