#include <Arduino.h>
#include "joint.h"
// ratio, microstep, max_speed, acceleration, bound, dir_pin, step_pin
// For all, max speed, acceleration, bound, and microstep need to be like tested
StepperJoint J1(25, 16, 1000, 150, 45, 22, 32);
StepperJoint J2(25, 16, 500, 150, 45, 25, 26);
StepperJoint J3(25, 16, 1000, 250, 45, 23, 33);
StepperJoint J4(15, 16, 1000, 500, 45, 13, 4);
StepperJoint J5(15, 16, 1000, 500, 45, 17, 16);

// bound,pulse
ServoJoint J6(45, 27);
ServoJoint gripper(45, 21);

// Positive Directions (J1, J2, J3, J4, J5)
// CW, CW, CW, CCW, CW

bool atHome = true;   

void runMove() {
    if (atHome) {
        // J1.moveToAngle(45);
        // J2.moveToAngle(45);
        // J3.moveToAngle(-60);
        // J3.moveToAngle(30);
        // J4.moveToAngle(-20);
        // J5.moveToAngle(90);
    } else {
        // J1.moveToAngle(0);
        // J2.moveToAngle(0);
        // J3.moveToAngle(0);
        // J4.moveToAngle(0);
        // J5.moveToAngle(0);
    }
    atHome = !atHome;
}

void setup() {
    Serial.begin(115200);

    pinMode(18, OUTPUT);   // J4 MS1
    // J4 MS2 is already on 3.3V
    pinMode(19, OUTPUT);   // J5 MS1
    pinMode(14, OUTPUT);   // J5 MS2
    digitalWrite(18, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(14, HIGH);

    Serial.println("Ready. Press SPACE in the Serial Monitor to run the move.");
}

void loop() {
    if (Serial.available() > 0) {
        char c = Serial.read();
        if (c == ' ') {
            runMove();
            Serial.println(atHome ? "Moving to 0" : "Moving out");
        }
    }
    J1.update();
    J2.update();
    J3.update();
    J4.update();
    J5.update();
}
