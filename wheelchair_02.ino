#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor1(1, MOTOR12_1KHZ); // Motor connected to M1 port
AF_DCMotor motor2(2, MOTOR12_1KHZ); 


Servo myservo;

int joystickX = A0;
int joystickY = A1;
int switchPin = 2;

int joystickValueX;
int joystickValueY;
int switchState;
int servoPos = 0;

void setup() {

    motor1.setSpeed(250);
  motor2.setSpeed(250);

  pinMode(switchPin, INPUT_PULLUP);
  myservo.attach(9);
}

void loop() {
  joystickValueX = analogRead(joystickX);
  joystickValueY = analogRead(joystickY);
  switchState = digitalRead(switchPin);
  
  if (joystickValueY < 400) { // Move forward
    motor1.run(FORWARD);
    motor2.run(FORWARD);
  
  } else if (joystickValueY > 600) { // Move backward
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
 
  } else { // Stop
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  
  }

  if (joystickValueX < 400) { // Turn left
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
 
  } else if (joystickValueX > 600) { // Turn right
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
 
  } else { // Stop turning
    motor1.run(RELEASE);
    motor2.run(RELEASE);

  }
  
  if (switchState == LOW) { // Slowly move servo motor
    if (servoPos == 0) {
      for (int i = 0; i <= 90; i++) {
        myservo.write(i);
        delay(15);
      }
      servoPos = 1;
    } else {
      for (int i = 90; i >= 0; i--) {
        myservo.write(i);
        delay(15);
      }
      servoPos = 0;
    }
  }
}
