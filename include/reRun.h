#pragma once
#include <list>
#include <string>
#include "main.h"

class reRun{
public:
  reRun(int i[]){
    for (int a = 0; a < sizeof(&i)/sizeof(i[0]); a++){
      motorToRecord.push_back(i[a]);
    }
  }
  void recordRun();
  void playRun();
  void addMotor(int motor);
  void saveRun(std::string name);
  void setSampleRate(int ms){sampleRate = ms;};
private:
  int sampleRate = 10;
  struct motorValues{int motor; int voltage; double ticks; int current; double velocity;};
  std::list<motorValues> movement;
  std::list<int> motorToRecord;
};
