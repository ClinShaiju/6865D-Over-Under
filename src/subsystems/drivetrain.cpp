#include "main.h"
#include "subsystems/drivetrain.h"

pros::Controller controller(pros::E_CONTROLLER_MASTER);

/*
################
-  DRIVETRAIN  -
################
 */

pros::Motor backLeft = pros::Motor(PORT_DRIVE_BACKLEFT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor frontLeft = pros::Motor(PORT_DRIVE_FRONTLEFT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor middleLeft = pros::Motor(PORT_DRIVE_MIDDLELEFT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor frontRight = pros::Motor(PORT_DRIVE_FRONTRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor backRight = pros::Motor(PORT_DRIVE_BACKRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor middleRight = pros::Motor(PORT_DRIVE_MIDDLERIGHT, pros::E_MOTOR_GEARSET_06, true);

pros::Motor_Group driveLeft = pros::Motor_Group({backLeft, frontLeft, middleLeft});
pros::Motor_Group driveRight = pros::Motor_Group({backRight, frontRight, middleRight});

// drivetrain settings
lemlib::Drivetrain drivetrain(&driveLeft, // left motor group
                              &driveRight, // right motor group
                              11.875, // 10 inch track width
                              lemlib::Omniwheel::NEW_4, // using new 4" omnis
                              300, // drivetrain rpm is 300
                              8 // chase power is 2. If we had traction wheels, it would have been 8
);

/*
###############
-  DRIVE PID  -
###############
*/

// lateral motion controller
lemlib::ControllerSettings linearController(40, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            250, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(3, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             22, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);

/*
##############
-  ODOMETRY  -
##############
*/

//pros::ADIEncoder xEncoder = pros::ADIEncoder(PORT_ADI_XENCODER_TOP, PORT_ADI_XENCODER_BOTTOM, true);
//pros::ADIEncoder yEncoder = pros::ADIEncoder(PORT_ADI_YENCODER_TOP, PORT_ADI_YENCODER_BOTTOM, false);

//lemlib::TrackingWheel xTracker(&xEncoder, 2.75, -1.00393701, 1);
//lemlib::TrackingWheel yTracker(&yEncoder, 2.75, -0.0196850394, 1);

pros::Imu inertial1 = pros::Imu(PORT_INERTIAL_1);
pros::Imu inertial2 = pros::Imu(PORT_INERTIAL_2);
std::vector<pros::Imu *> imuList{&inertial1};
std::vector<float> errorMultiplierList{1};
lemlib::ImuGroup imuGroup = lemlib::ImuGroup(imuList, errorMultiplierList);

lemlib::OdomSensors odomSensors(nullptr, // vertical tracking wheel 1, set to null
                                nullptr, // vertical tracking wheel 2, set to nullptr as we are using IMEs
                                nullptr, // horizontal tracking wheel 1
                                nullptr, // horizontal tracking wheel 2, set to nullptr as we don't have a second one
                                &imuGroup // inertial sensor
);

lemlib::Chassis chassis = lemlib::Chassis(drivetrain, linearController, angularController, odomSensors);


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

void arcadeDrive(double leftAxis, double rightAxis) {
    driveLeft = leftAxis + rightAxis;
    driveRight = leftAxis - rightAxis;
}

void tankDrive(double leftAxis, double rightAxis) {
    driveLeft = leftAxis;
    driveRight = rightAxis;
}