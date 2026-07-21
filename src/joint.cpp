#include "joint.h"

void StepperJoint::moveToAngle(float angle) {
    if (bound < angle) {
        angle = bound;
    }

    if (angle < -bound) {
        angle = -bound;
    }
    
    double base_steps = angle / stepangle;
    double micro_steps = base_steps * microstep;
    long total_steps = micro_steps * ratio;
    stepper.moveTo(total_steps);
}
int StepperJoint::getRatio() {
    return ratio;
}
int StepperJoint::getBound() {
    return bound;
}
int StepperJoint::getMicrostep() {
    return microstep;
}
double StepperJoint::getStepangle() {
    return stepangle;
}
int StepperJoint::getDirPin() {
    return dir_pin;
}
int StepperJoint::getStepPin() {
    return step_pin;
}
int StepperJoint::getAcceleration() {
    return acceleration;
}
int StepperJoint::getMaxSpeed() {
    return max_speed;
}
void StepperJoint::update() {
    stepper.run();
}


void ServoJoint::moveToAngle(int angle) {
    if (bound < angle) {
        angle = bound;
    }

    servo.write(angle);
}
int ServoJoint::getPulsePin() {
    return pulsePin;
}