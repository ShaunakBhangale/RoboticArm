#pragma once
#include <AccelStepper.h>
#include <ESP32Servo.h>


class StepperJoint {
private:
    int ratio;
    int microstep;
    int bound;
    int max_speed;
    int acceleration;
    double stepangle;

    int dir_pin;
    int step_pin;

    AccelStepper stepper;
public:
    StepperJoint(int ratio, int microstep, int max_speed, int acceleration, int bound, int dir_pin, int step_pin)
     : stepper(AccelStepper::DRIVER, step_pin, dir_pin) {
        
        this->ratio = ratio;
        this->microstep = microstep;
        this->bound = bound;
        this->dir_pin = dir_pin;
        this->step_pin = step_pin;
        this->stepangle = 1.8;
        this->acceleration = acceleration;
        this->max_speed = max_speed;

        stepper.setMaxSpeed(max_speed);
        stepper.setAcceleration(acceleration);
    }
    void moveToAngle(int angle);
    int getRatio();
    int getMicrostep();
    int getBound();
    int getStepPin();
    int getDirPin();
    int getMaxSpeed();
    int getAcceleration();
    double getStepangle();
    void update();
};

class ServoJoint {
private:
    int bound;
    int pulsePin;

    Servo servo;
public:
    ServoJoint(int bound, int pulsePin) {
        this->bound=bound;
        this->pulsePin=pulsePin;
        servo.attach(pulsePin);
    }
    void moveToAngle(int angle);
    int getPulsePin();
};

