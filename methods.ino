// Move Servo to Position
void move(Servo &servoObject, unsigned short angle, bool test = false) {
  if (angle > MAX_ANGLE) {
    Serial.println("Angle out of degree range");
    return 1;
  }

  unsigned short ddelay = (DELAY_MIL * abs(max(angle, servoObject.read()) - min(angle, servoObject.read())));
  servoObject.write(angle);

  if (test) {
    Serial.print("Angle : ");
    Serial.println(angle);
    Serial.print("Delay : ");
    Serial.println(ddelay);
  };

  delay(ddelay);
}

// Move Claw
void claw() {
  if (cclaw.read() == 90) {
    move(cclaw, 0);
  } else {
    move(cclaw, 90);
  }
}

// Test All Methods
void test() {
  Serial.println("Testing ...");
  delay(2000);
  move(Servo1, 180, true);
  move(Servo2, 180, true);
  move(Servo3, 180, true);
  move(Servo4, 180, true);
  move(Servo1, 0, true);
  move(Servo2, 0, true);
  move(Servo3, 0, true);
  move(Servo4, 0, true);
  claw();
  claw();
}

// Add Servo
void addServo(Servo &servoObject, uint8_t pin) {
  pinMode(pin, OUTPUT);
  servoObject.attach(pin);
  servoObject.write(0);
  delay(450);
}

// Joystick Controller Function
void joystick() {
  int reset = digitalRead(7);
  int claw_but = digitalRead(8);
  float lx = map(analogRead(A0), 0, 1023, -SENSITIVITY, SENSITIVITY);
  float ly = map(analogRead(A1), 1023, 0, -SENSITIVITY, SENSITIVITY);
  float rx = map(analogRead(A2), 0, 1023, -SENSITIVITY, SENSITIVITY);
  float ry = map(analogRead(A3), 1023, 0, -SENSITIVITY, SENSITIVITY);

  Servo1.write(constrain(Servo1.read() + ly, 0, 180));
  Servo2.write(constrain(Servo2.read() + lx, 0, 180));
  Servo3.write(constrain(Servo3.read() + ry, 0, 180));
  Servo4.write(constrain(Servo4.read() + rx, 0, 180));
  
  if (!reset) {
    Servo1.write(0);
    Servo2.write(0);
    Servo3.write(0);
    Servo4.write(0);
  }

  if (!claw_but) {
    claw();
  }

  delay(10);
}

// Predefined Loop
void loop() {
  if (JOYSTICK_ENABLED) {
    joystick();
  }
}
