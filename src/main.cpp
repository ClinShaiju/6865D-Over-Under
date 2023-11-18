#include "main.h"
#include "subsystems/drivetrain.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void screen() {
    // loop forever
    while (true) {

        float imu1RawHeading = imuGroup.get_raw_rotation(0) + 0;
//        float imu2RawHeading = imuGroup.get_raw_rotation(1) + 0;
        float imu1Heading = imuGroup.get_rotation(0) + 0;
//        float imu2Heading = imuGroup.get_rotation(1) + 0;
        float heading = imuGroup.get_rotation() + 0;

        lemlib::Pose pose = chassis.getPose(); // get the current position of the robot
        pros::lcd::print(0, "x: %f", pose.x); // print the x position
        pros::lcd::print(1, "y: %f", pose.y); // print the y position
        pros::lcd::print(2, "lemlib heading: %f", pose.theta); // print the heading
        pros::lcd::print(3, "ImuGroup heading: %f", (int)(heading*1000)%360000/1000.0); // print the heading
        pros::lcd::print(4, "imu1: %f - raw: %f", (int)(imu1Heading*1000)%360000/1000.0, ((int)(imu1RawHeading*1000)%360000/1000.0)); // print the heading
//        pros::lcd::print(5, "imu2: %f - raw: %f", (int)(imu2Heading*1000)%360000/1000.0, ((int)(imu2RawHeading*1000)%360000/1000.0)); // print the heading
        pros::delay(10);
    }
}

void initialize() {
    pros::lcd::initialize();
    pros::Task screenTask(screen);

    chassis.calibrate();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

// LemLib beta v0.5.0 code
//// Right Side Auton
//void autonomous() {
//    // Set starting position
//
//    // Wings out to push alliance preload near goal
//    pros::delay(200);
//    wingsOut();
//    pros::delay(200);
//    wingsIn();
//    pros::delay(500);
//
//    chassis.setPose(113, 18, 180);
//
//
//    // Turn to face the inside of the field
//    chassis.turnTo(113, 80, 2000);
//
//    // Arc turn to grab top left triball
//    intakeIn(); // Start intake
//    chassis.moveTo(77, 70, 310, 3000, false, true, 4000, 0.3);
//    pros::delay(750); // Wait for triball to get in the intake
//
//    // Turn to goal and push 2 triballs in
//    chassis.turnTo(120, 68, 1500); // Turn toward goal
//    chassis.moveTo(107, 68, 90, 1200, true, true, 4000, 0.3); // Drive toward goal, async
//    pros::delay(500); // Wait until triball is pushed in
//    intakeOut(); // While driving, push out triball in intake
//    pros::delay(1000); // Wait until triball is pushed in
//    intakeStop(); // Stop intake
//
//    // Arc turn to middle left triball
//    intakeIn(); // Start intake
//    chassis.moveTo(78, 48, 270, 2000, false, true, 4000, 0.3); // Async
//
//    // Maneuver around side of goal to push alliance triball and triball in intake into the goal
//    chassis.turnTo(120, 25, 2000); // Turn to face a bit before the goal
//    chassis.moveTo(120, 25, 100, 2000, false, true, 4000, 0.3); //Drive to a bit before the goal
//    chassis.moveTo(129, 55, 0, 2000, true, true, 4000, 0.3); // Push 2 triballs in
//    intakeOut(); // Release the triball in intake
//    pros::delay(2000);
//
//    // Move away from side of goal
//    chassis.moveTo(129, 40, 0, 2000, false, false, 4000, 0.3);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                0, 2000, false, false, 4000, 0.3);
//}

//// Left Side Auton
//void autonomous() {
//    chassis.setPose(32, 16, 180);
//    chassis.moveTo(12, 48, 180, 2000, false, false, 4000, 0.3);
//    pros::delay(500);
//    intakeOut();
//    chassis.moveTo(69, 12, 90, 2000, false, true, 4000, 0.6);
//    pros::delay(500);
//    chassis.moveTo(32, 16, 45, 2000, false, false, 4000, 0.3);
//    chassis.moveTo(32, 16, 45, 2000, false, false, 4000, 0.3);
//}

// Skills Auton
void autonomous() {
    tankDrive(-1, -1);
//    chassis.setPose(32, 16, 180);
//    chassis.moveTo(18, 18, 45, 2000, false, false, 4000, 0.3);
    startPuncher();
//    pros::delay(45000);
//    chassis.moveTo(108, 12, 90, 2000, false, true, 4000, 0.3);
//    chassis.turnTo(50, 12, 2000);
//    stopPuncher();
//    wingsOut();
//    chassis.moveTo(132, 24, 180, 2000, false, false, 4000, 0.3);
//    wingsIn();
//    chassis.turnTo(144, 24, 2000);
//    chassis.moveTo(84, 24, 90, 2000, false, false, 4000, 0.3);
//    chassis.turnTo(84, 0, 2000);
//    wingsOut();
//    chassis.moveTo(84, 24, 90, 2000, false, false, 4000, 0.3);
}


/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while (true) {
        int leftYAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightXAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        arcadeDrive(returnExponential(leftYAxis), returnExponential(rightXAxis));
        runIntake();
        runPuncherToggle();
        runWings();
        pros::delay(10);
    }
    // Set starting position

}