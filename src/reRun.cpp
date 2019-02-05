#include "reRun.h"


void reRun::addMotor(int motor){
  motorToRecord.push_back(motor);
}

void reRun::recordRun(){
  for(auto const& i : motorToRecord){
    pros::Motor motor(i);
    movement.push_back({i,motor.get_voltage(),motor.get_position(), motor.get_current_draw(), motor.get_actual_velocity()});
  }
}

void reRun::playRun(){
  for(auto const& i : movement){
    pros::Motor motor(i.motor);
    motor.set_voltage_limit(i.voltage + 100);
    motor.set_current_limit(i.current + 100);
    motor.move_absolute(i.ticks, i.velocity);
  }
}
