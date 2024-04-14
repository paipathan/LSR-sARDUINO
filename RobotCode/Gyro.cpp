#include "Gyro.h"

#define MPU_ADDRESS 0x68 // I2C address of your gyro

Gyro::Gyro() {}

void Gyro::begin() {
  Wire.begin();
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);
}

void Gyro::readData() {
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(0x3B); 
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDRESS, 14, true); 
  
  _rawX = Wire.read() << 8 | Wire.read(); // turn byte of data from i2c bus and shift it left 8 bits (x256), turning into usable integer
  _rawY = Wire.read() << 8 | Wire.read(); 
  _rawZ = Wire.read() << 8 | Wire.read(); 

  _angleX = (_rawX / _gyroScale);
  _angleY = (_rawY / _gyroScale);
  _angleZ = (_rawZ / _gyroScale);
}

float Gyro::getAngleX() {
  return _angleX;
}

float Gyro::getAngleY() {
  return _angleY;
}

float Gyro::getAngleZ() {
  return _angleZ;
}
