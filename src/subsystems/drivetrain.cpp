#include "main.h"
#include "subsystems/drivetrain.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/*
################
-  DRIVETRAIN  -
################
 */

pros::Motor backLeft = pros::Motor(1, pros::E_MOTOR_GEARSET_06, true);
pros::Motor frontLeft = pros::Motor(2, pros::E_MOTOR_GEARSET_06, true);
pros::Motor frontRight = pros::Motor(9, pros::E_MOTOR_GEARSET_06, false);
pros::Motor backRight = pros::Motor(10, pros::E_MOTOR_GEARSET_06, false);

pros::Motor_Group driveLeft = pros::Motor_Group({backLeft, frontLeft});
pros::Motor_Group driveRight = pros::Motor_Group({backRight, frontRight});

lemlib::Drivetrain_t drivetrain {
        &driveLeft, // left drivetrain motors
        &driveRight, // right drivetrain motors
        12.5590551, // track width
        4.125, // wheel diameter
        257.142857 // wheel rpm
};

/*
##############
-  ODOMETRY  -
##############
*/

pros::ADIEncoder xEncoder = pros::ADIEncoder('A', 'B', true);
pros::ADIEncoder yEncoder = pros::ADIEncoder('C', 'D', false);

lemlib::TrackingWheel xTracker(&xEncoder, 2.75, -1.00393701, 1);
lemlib::TrackingWheel yTracker(&yEncoder, 2.75, -0.0196850394, 1);

pros::Imu inertial = pros::Imu(4);

lemlib::OdomSensors_t odomSensors {
        &yTracker, // vertical tracking wheel 1
        nullptr, // vertical tracking wheel 2
        &xTracker, // horizontal tracking wheel 1
        nullptr, // we don't have a second tracking wheel, so we set it to nullptr
        &inertial, // inertial sensor
        ((362.9323 / 360.0))
};

/*
###############
-  DRIVE PID  -
###############
*/

//forward/backward pid
lemlib::ChassisController_t lateralController {
        8, // kP
        30, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
};

// turning PID
lemlib::ChassisController_t angularController {
        4, // kP
        40, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        0 // slew rate
};

lemlib::Chassis chassis = lemlib::Chassis(drivetrain, lateralController, angularController, odomSensors);


/*
#####################
-  DRIVE FUNCTIONS  -
#####################
*/

float getVelocityOutput(pros::MotorGroup &motors, int voltage) {

    float output = 0;
    if (motors.get_gearing()[0] == pros::E_MOTOR_GEARSET_06) output = (600.0 / 127.0) * voltage;
    if (motors.get_gearing()[0] == pros::E_MOTOR_GEARSET_18) output = (200.0 / 127.0) * voltage;
    if (motors.get_gearing()[0] == pros::E_MOTOR_GEARSET_36) output = (100.0 / 127.0) * voltage;
    return output;

}

void arcadeDrive(int leftAxis, int rightAxis) {

    float leftOutput = getVelocityOutput(driveLeft, leftAxis);
    float rightOutput = getVelocityOutput(driveLeft, rightAxis);

    driveLeft.move_velocity(leftOutput + rightOutput);
    driveRight.move_velocity(leftOutput - rightOutput);

}
void tankDrive(int leftAxis, int rightAxis) {

    float leftOutput = getVelocityOutput(driveLeft, leftAxis);
    float rightOutput = getVelocityOutput(driveRight, rightAxis);

    driveLeft.move_velocity(leftOutput);
    driveRight.move_velocity(rightOutput);

}