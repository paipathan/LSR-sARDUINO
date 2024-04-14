#include "Servo.h"

ServoMotor::ServoMotor(int pin) {
  _pin = pin;
  _servo.attach(_pin);
}

void ServoMotor::setPosition(int angle) {
  angle = constrain(angle, 0, 180);
  _servo.write(angle);
}
