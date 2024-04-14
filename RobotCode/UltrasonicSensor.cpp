#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
  _trigPin = trigPin;
  _echoPin = echoPin;

  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

float UltrasonicSensor::getDistance() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  unsigned long duration = pulseIn(_echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  return distance;
}
