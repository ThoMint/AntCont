#ifndef STEPMOT_H
#define STEPMOT_H

#include "Arduino.h"
#include <Stepper.h>

#define IN1 5
#define IN2 18
#define IN3 19
#define IN4 21
#define STEPS_PER_REV 200

void initStepper();
void disarmStepper();
void cmdStepper(String function, int speed, int steps);

#endif
