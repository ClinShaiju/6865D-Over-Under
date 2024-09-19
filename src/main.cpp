#include "main.h"
#include "subsystems/drivetrain.h"


LV_IMG_DECLARE(Buccees);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */


void initialize() {
    lv_obj_t *img1 = lv_img_create(lv_scr_act(), NULL);
    lv_img_set_src(img1, &Buccees);
    lv_obj_align(img1, NULL, LV_ALIGN_CENTER, 0, 0);
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
//ASSET(endTriballPush_txt);

// LemLib beta v0.5.0 code
// Far Side Auton
ASSET(underbar_txt);

void skillsAuton() {
    startPuncher();
    chassis.setPose(-45.252, -53.523, 55);
    pros::delay(45000);
    stopPuncher();
    chassis.turnTo(-32, -59, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(35.5, -58, 90, 2000);
    chassis.waitUntilDone();
    chassis.turnTo(35.5, -50, 2000);
    chassis.waitUntilDone();

    chassis.moveToPose(35.5, -40, 0, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(16, -12, 45, 2000);
    chassis.waitUntilDone();
    frontWingsOut();
    chassis.moveToPose(48, 0, 90, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(30, 0, 90, 2000, {.forwards=false});

}

void far5ball() {
    chassis.setPose(41.5, -47.75, 0);
    intakeIn();
    chassis.moveToPose(10, 2, -42, 2500); // Top left triball
    frontRightWingOut();
    pros::delay(500);
    frontRightWingIn();
    chassis.waitUntil(50);
    chassis.cancelAllMotions();
    chassis.moveToPose(48, 3, 90, 1500); // Push both triballs into goal
    chassis.waitUntil(5);
    frontLeftWingOut();
    chassis.waitUntil(10);
    frontRightWingOut();
    chassis.waitUntil(30);
    intakeOut();
    chassis.waitUntil(32);
    chassis.cancelAllMotions();
    chassis.moveToPose(30, 3, 90, 2000, {.forwards = false}); // Backwards
    frontWingsIn();
    chassis.waitUntil(10);
    chassis.cancelAllMotions();
    chassis.moveToPose(8, -14, 250, 1500); // Grab bottom left triball
    intakeIn();
    chassis.waitUntilDone();
    chassis.setPose(9, -20, chassis.getPose().theta);

    chassis.moveToPose(45, -3, 90, 2000); // Push both triballs into goal
    chassis.waitUntil(20);
    frontWingsOut();
    intakeOut();
    chassis.waitUntilDone();
    chassis.moveToPose(30, -3, 90, 2000, {.forwards = false}); // Backwards
    frontWingsIn();
    chassis.waitUntil(8);
    chassis.cancelAllMotions();
    chassis.moveToPose(35, -58, 170, 1500);
    chassis.waitUntilDone();
    chassis.moveToPose(15, -58, 270, 1500);
    intakeIn();
    chassis.waitUntilDone();
    chassis.moveToPose(38, -48, 240, 1500, {.forwards=false});
    chassis.waitUntilDone();
//    chassis.moveToPose(55, -38, 200, 1500);
//    chassis.waitUntilDone();
    chassis.moveToPose(60, -16, 180, 1500, {.forwards=false, .minSpeed=127});
    intakeOut();

    chassis.waitUntilDone();
}

void close3ball() {
    chassis.setPose(-41.5, -47.75, 0);
    intakeIn();
    chassis.moveToPose(-24, 0, 0, 2000);
    chassis.waitUntil(48);
    chassis.cancelAllMotions();
    chassis.moveToPose(-48, -48, 90, 2000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPose(0, -60, 270, 2000);
    intakeOut();
    chassis.waitUntilDone();


}

void farSafe2ball() {
    chassis.setPose(10, -60, 270);
    intakeIn();
    chassis.moveToPose(0, -60, 270, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(36, -60, 270, 2000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPose(60, -30, 180, 2000, {.forwards=false});
    chassis.waitUntilDone();
    chassis.moveToPoint(48, -48, 2000);
    chassis.waitUntilDone();
    chassis.moveToPose(55, -30, 0, 2000);
    chassis.waitUntil(5);
    intakeOut();
    chassis.waitUntilDone();
    chassis.moveToPoint(55, -40, 2000, false);
    chassis.waitUntilDone();
    chassis.moveToPoint(55, -30, 2000);
    chassis.waitUntilDone();
    chassis.moveToPoint(55, -40, 2000, false);
    chassis.waitUntilDone();
}

void oneball() {
    chassis.moveToPoint(0, -60, 2000, false);
    chassis.moveToPoint(0, 0, 500, true);

}

void awp() {
    chassis.setPose(-51, -59, 135);
    backRightWingOut();
    pros::delay(1000);
    chassis.turnTo(-60, 60, 1000, true);
    chassis.waitUntilDone();
    backWingsIn();
    chassis.turnTo(-10, -64, 1000, true);
    chassis.waitUntilDone();

    chassis.moveToPose(-14, -60, 90, 2000);
    chassis.waitUntilDone();
    intakeOut();


}

void autonomous() {
    dropIntake();
//    oneball();
    far5ball();
//    close3ball();
//    farSafe2ball();
//    skillsAuton();
//    awp();
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
    // drive curve adjustments
    leftType = 1;
    rightType = 2;
    leftT = 10;
    rightT = 6;
    int startTime = pros::c::millis();
    bool past30 = false;
    bool past15 = false;
    bool past10 = false;
    dropIntake();
    while (true) {
        int timeLeft = 105000 - (pros::c::millis() - startTime);
        int leftYAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int rightXAxis = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2) && timeLeft < 300000) {
            leftYAxis *= .5;
            rightXAxis *= .5;
        }

//        runDriveCurveTester();
        arcadeDrive(returnExponential(leftYAxis, leftType, leftT), returnExponential(rightXAxis, rightType, rightT));
        runIntake();
//        runPuncherToggle();
        runFrontWings();
        runBackWings();
        runPtoToggle(timeLeft);
        runLatchToggle(timeLeft);
        if (timeLeft < 30000 && !past30) {

            controller.rumble(".");
            past30 = true;
        }
        if (timeLeft < 15000 && !past15) {
            controller.rumble("..");
            past15 = true;
        }
        if (timeLeft < 10000 && !past10){

            controller.rumble("-");
            past10 = true;
        }
        autoHang(timeLeft);
        pros::delay(10);

    }

}