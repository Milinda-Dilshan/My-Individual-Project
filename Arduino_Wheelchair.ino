
 #include <AFMotor.h>
 #include <Servo.h>

AF_DCMotor leftmotors(4, MOTOR12_64KHZ);

AF_DCMotor rightmotors(3, MOTOR12_64KHZ);

Servo servo_motor; 

#define trigPin 12 // define the pins of the distance sensor

#define echoPin 13

void setup() {



  pinMode (8, INPUT_PULLUP);
  pinMode (7, INPUT_PULLUP);
  pinMode (4, INPUT_PULLUP);
  pinMode (2, INPUT_PULLUP);
  pinMode (5, INPUT_PULLUP);

  leftmotors.setSpeed(255); // set the speed to full speed 255/255

rightmotors.setSpeed(255); //set the speed to full speed 255/255

  servo_motor.attach(10);

pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)

pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)

}


void loop() {
  
  int Forwardbutton = digitalRead (8);
  int Backwardbutton = digitalRead (7);
  int Rightbutton = digitalRead (4);
  int Leftbutton = digitalRead (2);
  int servobutton = digitalRead (5);
 
 
long duration, distance; // start the scan

digitalWrite(trigPin, LOW);

delayMicroseconds(2); // delays are required for a succesful sensor operation.

digitalWrite(trigPin, HIGH);

delayMicroseconds(10); //this delay is required as well!

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = ((duration/2) / (29.1));// convert the distance to centimeters.

if (distance < 20) /*if there's obstacle 10 centimers ahead, do the following: */ {


BACKW();


}

else if (Forwardbutton == HIGH) {



delay (500);

FORW();


}
if (Leftbutton == HIGH) {



delay (500);

 LEFT();


}
if (Backwardbutton == HIGH) {



delay (500);

BACKW();


}
if (Rightbutton == HIGH) {



delay (500);

RIGHT();


}

if (servobutton == HIGH) {


servo_motor.write(115);             
  delay(2000);

}

}

void FORW() {

leftmotors.run(FORWARD); // 2 left motors go in forward direction

rightmotors.run(FORWARD); // 2 right motors go in forward direction

}

void BACKW() {

leftmotors.run(BACKWARD); // 2 left motors go in backward direction

rightmotors.run(BACKWARD); // 2 right motors go in backward direction

}

void STOP() {

leftmotors.run(RELEASE); // stop 2 left motors

rightmotors.run(RELEASE); // stop 2 right motors

}
void RIGHT(){

leftmotors.run(FORWARD); //2 left motors go in forward direction

rightmotors.run(BACKWARD); //2 right motors go in backward direction. This make the robot spin to the left 90 degree.

}

void LEFT() {

leftmotors.run(BACKWARD); //the other way.

rightmotors.run(FORWARD);

}



