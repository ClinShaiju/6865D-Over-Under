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
pros::Motor middleLeft = pros::Motor(PORT_DRIVE_MIDDLELEFT, pros::E_MOTOR_GEARSET_06, true);
pros::Motor frontRight = pros::Motor(PORT_DRIVE_FRONTRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor backRight = pros::Motor(PORT_DRIVE_BACKRIGHT, pros::E_MOTOR_GEARSET_06, false);
pros::Motor middleRight = pros::Motor(PORT_DRIVE_MIDDLERIGHT, pros::E_MOTOR_GEARSET_06, false);

pros::Motor_Group driveLeft = pros::Motor_Group({backLeft, frontLeft, middleLeft});
pros::Motor_Group driveRight = pros::Motor_Group({backRight, frontRight, middleRight});

lemlib::Drivetrain_t drivetrain {
        &driveLeft, // left drivetrain motors
        &driveRight, // right drivetrain motors
        12.5590551, // track width
        4.125, // wheel diameter
        257.142857, // wheel rpm
        4000 // chase power
};

/*
##############
-  ODOMETRY  -
##############
*/

pros::ADIEncoder xEncoder = pros::ADIEncoder(PORT_ADI_XENCODER_TOP, PORT_ADI_XENCODER_BOTTOM, true);
pros::ADIEncoder yEncoder = pros::ADIEncoder(PORT_ADI_YENCODER_TOP, PORT_ADI_YENCODER_BOTTOM, false);

lemlib::TrackingWheel xTracker(&xEncoder, 2.75, -1.00393701, 1);
lemlib::TrackingWheel yTracker(&yEncoder, 2.75, -0.0196850394, 1);

pros::Imu inertial1 = pros::Imu(PORT_INERTIAL_1);
pros::Imu inertial2 = pros::Imu(PORT_INERTIAL_2);
std::vector<pros::Imu*> imuList{&inertial1};
std::vector<float> errorMultiplierList{1};
lemlib::ImuGroup imuGroup = lemlib::ImuGroup(imuList, errorMultiplierList);


lemlib::OdomSensors_t odomSensors {
        nullptr,//&yTracker, // vertical tracking wheel 1
        nullptr, // vertical tracking wheel 2
        nullptr,//&xTracker, // horizontal tracking wheel 1
        nullptr, // we don't have a second tracking wheel, so we set it to nullptr
        &imuGroup
};

/*
###############
-  DRIVE PID  -
###############
*/

//forward/backward pid
lemlib::ChassisController_t lateralController {
        11, // kP
        5, // kD
        1, // smallErrorRange
        100, // smallErrorTimeout
        3, // largeErrorRange
        500, // largeErrorTimeout
        5 // slew rate
};

// turning PID
lemlib::ChassisController_t angularController {
    3, // kP
        1, // kD
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

void arcadeDrive(double leftAxis, double rightAxis) {
    driveLeft = leftAxis + rightAxis;
    driveRight = leftAxis - rightAxis;
}
void tankDrive(double leftAxis, double rightAxis) {
    driveLeft = leftAxis;
    driveRight = rightAxis;
}