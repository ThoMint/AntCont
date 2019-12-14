#include "StepMotor.h"

Stepper stepper(STEPS_PER_REV,IN1,IN2,IN3,IN4);

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

void cmdStepper(String function, int speed, int steps)
{
  if(function=="f")
  {
    stepper.setSpeed(speed);
    stepper.step(steps);
  }
  if(function=="b")
  {
    stepper.setSpeed(speed);
    stepper.step(-steps);
  }
  if(function=="d")
  {
    disarmStepper();
  }
}
