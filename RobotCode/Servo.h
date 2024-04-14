#ifndef SERVO_H
#define SERVO_H

#include <Arduino.h>
#include <Servo.h>

class ServoMotor {
  public:
    ServoMotor(int pin);

    void setPosition(int angle);

  private:
    Servo _servo;
    int _pin;
};

#endif
