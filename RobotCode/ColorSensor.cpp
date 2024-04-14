#include "ColorSensor.h"

ColorSensor::ColorSensor(int S0, int S1, int S2, int S3, int out) {
  _S0 = S0;
  _S1 = S1;
  _S2 = S2;
  _S3 = S3;
  _out = out;
}

void ColorSensor::begin() {
  pinMode(_S0, OUTPUT);
  pinMode(_S1, OUTPUT);
  pinMode(_S2, OUTPUT);
  pinMode(_S3, OUTPUT);
  pinMode(_out, INPUT);
}

void ColorSensor::setColorMode() {
  digitalWrite(_S2, LOW);
  digitalWrite(_S3, LOW);
}

void ColorSensor::setFrequencyScaling(int scaling) { // control sensor's sensitivity
  if (scaling == 0) {
    digitalWrite(_S0, LOW);
    digitalWrite(_S1, LOW);
  } else if (scaling == 1) {
    digitalWrite(_S0, HIGH);
    digitalWrite(_S1, LOW);
  } else if (scaling == 2) {
    digitalWrite(_S0, LOW);
    digitalWrite(_S1, HIGH);
  } else if (scaling == 3) {
    digitalWrite(_S0, HIGH);
    digitalWrite(_S1, HIGH);
  }
}

bool ColorSensor::detectColor(uint32_t hexColor) {
  int red = readRed();
  int green = readGreen();
  int blue = readBlue();

  uint32_t measuredColor = (red << 16) | (green << 8) | blue;

  
  return abs(measuredColor - hexColor) <= _tolerance;
}

int ColorSensor::readRed() {
  digitalWrite(_S2, LOW);
  digitalWrite(_S3, HIGH);
  delay(100);
  return pulseIn(_out, LOW);
}

int ColorSensor::readGreen() {
  digitalWrite(_S2, HIGH);
  digitalWrite(_S3, HIGH);
  delay(100);
  return pulseIn(_out, LOW);
}

int ColorSensor::readBlue() {
  digitalWrite(_S2, LOW);
  digitalWrite(_S3, LOW);
  delay(100);
  return pulseIn(_out, LOW);
}
