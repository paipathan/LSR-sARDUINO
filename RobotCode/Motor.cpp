#include "Motor.h"

Motor::Motor(int pwmPin, int dirPin1, int dirPin2) {
  _pwmPin = pwmPin;
  _dirPin1 = dirPin1;
  _dirPin2 = dirPin2;

  pinMode(_pwmPin, OUTPUT);
  pinMode(_dirPin1, OUTPUT);
  pinMode(_dirPin2, OUTPUT);
}

void Motor::moveForward() {
  digitalWrite(_dirPin1, HIGH);
  digitalWrite(_dirPin2, LOW);
  analogWrite(_pwmPin, 255);
}

void Motor::moveBackward() {
  digitalWrite(_dirPin1, LOW);
  digitalWrite(_dirPin2, HIGH);
  analogWrite(_pwmPin, 255);
}

void Motor::turnLeft() {
  digitalWrite(_dirPin1, LOW);
  digitalWrite(_dirPin2, HIGH);
  analogWrite(_pwmPin, 150);
}

void Motor::turnRight() {
  digitalWrite(_dirPin1, HIGH);
  digitalWrite(_dirPin2, LOW);
  analogWrite(_pwmPin, 150);
}

void Motor::stop() {
  digitalWrite(_dirPin1, LOW);
  digitalWrite(_dirPin2, LOW);
  analogWrite(_pwmPin, 0);
}
