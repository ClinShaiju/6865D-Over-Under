#include "main.h"

extern pros::Controller controller;
extern lemlib::Chassis chassis;

float getVelocityOutput(pros::MotorGroup &motors, int voltage);
float getVelocityOutput(pros::Motor &motors, int voltage);

void arcadeDrive(double, double);
void tankDrive(double, double);