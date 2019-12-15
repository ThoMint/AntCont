#include "StepMotor.h"

Stepper stepper(STEPS_PER_REV,IN1,IN2,IN3,IN4);
int currPos = 0;

void initStepper()
{
  stepper.setSpeed(15);
  stepper.step(3);
  stepper.step(-3);
}

void disarmStepper()
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void cmdStepper(String function, int speed, int pos)
{
  if(function=="d")
  {
    stepper.setSpeed(speed);
    stepper.step(pos-currPos);
    currPos = pos;
  }
  else if(function=="d")
  {
    disarmStepper();
  }
}
