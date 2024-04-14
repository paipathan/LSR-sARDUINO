#ifndef GYRO_H
#define GYRO_H

#include <Arduino.h>
#include <Wire.h>

class Gyro {
  public:
    Gyro();
    void begin();
    void readData();
    float getAngleX();
    float getAngleY();
    float getAngleZ();

  private:
    float _angleX, _angleY, _angleZ;
    int16_t _rawX, _rawY, _rawZ;
    float _gyroScale = 131.0;
};

#endif
