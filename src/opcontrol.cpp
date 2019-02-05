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
pros::Controller master(CONTROLLER_MASTER);

int motors[] = {1,2,3,4,5,6,7,8};

reRun rerun(motors);

bool recordFlag;
bool playFlag;


void rerun_Func(){
	if(master.get_digital_new_press(DIGITAL_A) && !recordFlag && !playFlag){
		recordFlag = true;
	}else if(master.get_digital_new_press(DIGITAL_A) && recordFlag && !playFlag){
		recordFlag = false;
	}
	if(master.get_digital_new_press(DIGITAL_B) && !recordFlag && !playFlag){
		playFlag = true;
	}else if(master.get_digital_new_press(DIGITAL_B) && !recordFlag && playFlag){
		playFlag = false;
	}
	if(recordFlag && !playFlag){
		rerun.recordRun();
	}
	if(!recordFlag && playFlag){
		rerun.playRun();
	}
}


void opcontrol() {
	while (1) {
		rerun_Func();
		pros::delay(10);
	}
}
