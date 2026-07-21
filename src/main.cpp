#include <Arduino.h>
#include "joint.h"
#include <sstream>
#include <vector>
// ratio, microstep, max_speed, acceleration, bound, dir_pin, step_pin
// For all, max speed, acceleration, bound, and microstep need to be like tested
StepperJoint J1(25, 16, 2000, 100, 60, 22, 32);
StepperJoint J2(25, 16, 500, 150, 60, 25, 26);
StepperJoint J3(25, 16, 500, 150, 120, 23, 33);
StepperJoint J4(15, 16, 2000, 500, 90, 13, 4);
StepperJoint J5(15, 16, 2000, 500, 120, 17, 16);

// bound,pulse
ServoJoint J6(180, 27);
ServoJoint gripper(45, 21);

// Positive Directions (J1, J2, J3, J4, J5)
// CW, CW, CW, CCW, CW

void runMove(std::vector<float> joint_angles) {
        J1.moveToAngle(joint_angles[0]);
        J2.moveToAngle(joint_angles[1]);
        J3.moveToAngle(joint_angles[2]);
        J4.moveToAngle(-joint_angles[3]);
        J5.moveToAngle(joint_angles[4]);
        J6.moveToAngle(joint_angles[5]);
}

void setup() {
    Serial.begin(9600);

    pinMode(18, OUTPUT);   // J4 MS1
    // J4 MS2 is already on 3.3V
    pinMode(19, OUTPUT);   // J5 MS1
    pinMode(14, OUTPUT);   // J5 MS2
    digitalWrite(18, HIGH);
    digitalWrite(19, HIGH);
    digitalWrite(14, HIGH);

}

void loop() {
    if (Serial.available()) {
        String line = Serial.readStringUntil('\n');
        std::stringstream ss(line.c_str());        
        std::string token;

        std::vector<float> joint_angles;     
        while(std::getline(ss, token, ' ')) {
            float angle = std::stof(token);
            joint_angles.push_back(angle);
        }
    if (joint_angles.size() == 6) 
        runMove(joint_angles);
    }
    J1.update();
    J2.update();
    J3.update();
    J4.update();
    J5.update();
}
