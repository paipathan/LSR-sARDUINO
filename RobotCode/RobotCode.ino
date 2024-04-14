#include <Arduino.h>
#include "Button.h"
#include "ColorSensor.h"
#include "Gyro.h"
#include "Led.h"
#include "Motor.h"
#include "Servo.h"
#include "UltrasonicSensor.h"


const int motorPWMPin = 9;
const int motorDirPin1 = 8;
const int motorDirPin2 = 7;
const int trigPin = 12;
const int echoPin = 11;


Motor motor(motorPWMPin, motorDirPin1, motorDirPin2);
UltrasonicSensor ultrasonicSensor(trigPin, echoPin);

void setup() {
  Serial.begin(9600);
  motor.moveForward(); 
}

void loop() {
  
  if (ultrasonicSensor.getDistance() <= 5) {
    motor.stop();
    delay(1000); 
    motor.turnRight(); 
    delay(1000); 
    motor.moveForward(); 
  }
}
