void move(Servo &servoObject, unsigned int angle) {
  if (angle > 180) {
    Serial.println("Angle out of degree range");
    return 1;
  }

  unsigned long ddelay = (DELAY_MIL * abs(max(angle, servoObject.read()) - min(angle, servoObject.read())));
  servoObject.write(angle);

  Serial.print("Moving Servo to: ");
  Serial.println(angle);

  delay(ddelay);
}

void claw(bool grab) {
  if (grab) {
    move(claw_pin, 180);
  } else {
    move(claw_pin, 0);
  }
}

void loop() {}

void test() {
  Serial.println("Testing ...");
  delay(2000);
  move(claw_pin, 180);
  move(Servo1, 180);
  move(claw_pin, 0);
  move(Servo1, 0);
  claw(true);
  claw(false);
}

void addServo(Servo &servoObject, uint8_t pin) {
  servoObject.attach(pin);
  servoObject.write(0);
  delay(450);
}