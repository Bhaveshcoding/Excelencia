// Variables & Library
#include <Servo.h>
#define DELAY_MIL 2.5

Servo claw_pin; // Claw
Servo Servo1; // Top
Servo Servo2; // Middle
Servo Servo3; // Bottom
Servo Servo4; // Rotater

// Functions
void setup() {
  Serial.begin(2400);
  addServo(claw_pin, 2);
  addServo(Servo1, 3);
  addServo(Servo2, 4);
  addServo(Servo3, 5);
  addServo(Servo4, 6);
  Serial.println("Starting ...");
  perform();
}

void perform() {
  test();
}
