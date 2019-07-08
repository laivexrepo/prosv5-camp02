#include "main.h"

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

#define LEFT_WHEELS_PORT 1
#define RIGHT_WHEELS_PORT 10

void opcontrol() {
  pros::Motor left_wheels (LEFT_WHEELS_PORT);
  pros::Motor right_wheels (RIGHT_WHEELS_PORT, true);
  pros::Controller master (CONTROLLER_MASTER);

  while (true) {
    int power = master.get_analog(ANALOG_LEFT_Y);
    int turn = master.get_analog(ANALOG_RIGHT_X);
    int left = power + turn;
    int right = power - turn;
    left_wheels.move(left);
    right_wheels.move(right);

    pros::delay(2);
  }
}
