// Variables & Library
#include <Servo.h>
#define DELAY_MIL 2.5
#define JOYSTICK_ENABLED true
#define MAX_ANGLE 180
#define SENSITIVITY 3

Servo cclaw; // Claw
Servo Servo1; // Top
Servo Servo2; // Middle
Servo Servo3; // Bottom
Servo Servo4; // Rotater

// Functions
void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  addServo(cclaw, 2);
  addServo(Servo1, 3);
  addServo(Servo2, 4);
  addServo(Servo3, 5);
  addServo(Servo4, 6);
  Serial.println("Starting ...");
  if (!JOYSTICK_ENABLED) {
    perform();
  }
}

void perform() {
  test();
}
