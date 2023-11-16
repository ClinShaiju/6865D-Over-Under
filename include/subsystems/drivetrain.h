#include "main.h"

extern pros::Controller controller;
extern lemlib::Chassis chassis;
extern lemlib::ImuGroup imuGroup;

float getVelocityOutput(pros::MotorGroup &motors, int voltage);
float getVelocityOutput(pros::Motor &motors, int voltage);

void arcadeDrive(double, double);
void tankDrive(double, double);