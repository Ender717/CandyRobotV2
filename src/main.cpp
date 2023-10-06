#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

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
void autonomous() {}

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
void opcontrol()
{
    static constexpr uint8_t LEFT_DRIVE_1_PORT{};
    static constexpr uint8_t LEFT_DRIVE_2_PORT{};
    static constexpr uint8_t LEFT_DRIVE_3_PORT{};

    static constexpr uint8_t RIGHT_DRIVE_1_PORT{};
    static constexpr uint8_t RIGHT_DRIVE_2_PORT{};
    static constexpr uint8_t RIGHT_DRIVE_3_PORT{};

    static constexpr uint8_t CATAPULT_1_PORT{};
    static constexpr uint8_t CATAPULT_2_PORT{};
    static constexpr uint8_t CATAPULT_ROTATION_PORT{};

    static constexpr int32_t CATAPULT_LOADED_POSITION{};
    static constexpr int32_t CATAPULT_FIRED_POSITION{};

    static constexpr bool TANK_DRIVE{};
    static constexpr pros::controller_digital_e_t CATAPULT_BUTTON{};

    pros::Controller master{pros::E_CONTROLLER_MASTER};
    pros::MotorGroup leftDriveMotors{LEFT_DRIVE_1_PORT, LEFT_DRIVE_2_PORT, LEFT_DRIVE_3_PORT};
    pros::MotorGroup rightDriveMotors{RIGHT_DRIVE_1_PORT, RIGHT_DRIVE_2_PORT, RIGHT_DRIVE_3_PORT};
    pros::MotorGroup catapultMotors{CATAPULT_1_PORT, CATAPULT_2_PORT};
    pros::Rotation catapultRotation{CATAPULT_ROTATION_PORT};

    int32_t leftDrivePower{};
    int32_t rightDrivePower{};
    uint8_t catapultState{};

    while (true)
    {
        if (TANK_DRIVE)
        {
            leftDrivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
            rightDrivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
        }
        else
        {
            leftDrivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) +
                             master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
            rightDrivePower = master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) -
                             master.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
        }
        leftDriveMotors.move(leftDrivePower);
        rightDriveMotors.move(rightDrivePower);

        switch (catapultState)
        {
        case 0:
            if (master.get_digital_new_press(CATAPULT_BUTTON))
            {
                catapultState = 1;
                catapultMotors.move(127);
            }
            break;
        case 1:
            if (catapultRotation.get_angle() > CATAPULT_LOADED_POSITION)
                catapultState = 2;
            break;
        case 2:
            if (catapultRotation.get_angle() < CATAPULT_FIRED_POSITION)
                catapultState = 3;
            break;
        case 3:
            if (catapultRotation.get_angle() > CATAPULT_LOADED_POSITION)
            {
                catapultState = 0;
                catapultMotors.move(0);
            }
            break;
        }

        pros::delay(10);
    }
}