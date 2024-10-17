// Variables & Library
#include <Servo.h>
#define DELAY_MIL 2.5

Servo claw_pin;
Servo Servo1;

// Functions
void setup() {
  Serial.begin(2400);
  addServo(Servo1, 2); addServo(claw_pin, 3);
  Serial.println("Starting ...");
  perform();
}

void perform() {
  test();
}
