#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
  public:
    Motor(int pwmPin, int dirPin1, int dirPin2);

    void moveForward();
    void moveBackward();
    void turnLeft();
    void turnRight();
    void stop();

  private:
    int _pwmPin;
    int _dirPin1;
    int _dirPin2;
};

#endif
