#include <Arduino.h>
#include "joint.h"
// ratio, microstep, max_speed, acceleration, bound, dir_pin, step_pin
// For all, max speed, acceleration, bound, and microstep need to be like tested
StepperJoint J1(25, 16, 1000, 500, 45, 22, 32); 
StepperJoint J2(25, 16, 1000, 500, 45, 25, 26);
StepperJoint J3(25, 16, 1000, 500, 45, 23, 33);
StepperJoint J4(15, 16, 1000, 500, 45, 17, 16);
StepperJoint J5(15, 16, 1000, 500, 45, 13, 4);
// bound,pulse
ServoJoint J6(45, 27);
ServoJoint gripper(45, 21);
void setup() {
    pinMode(18, OUTPUT);   // J4 MS1
    // J4 MS2 is already on 3.3V
    pinMode(19, OUTPUT);   // J5 MS1
    pinMode(14, OUTPUT);   // J5 MS2
    digitalWrite(18, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(14, HIGH);

    J1.moveToAngle(45);
}

void loop() {
  J1.update();
}
