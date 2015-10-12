/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */

int motorON = 16;
int motorDir = 14;


int es1 = 13;
int es2 = 4;
int es3 = 5;

int openDoorCmd = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.

  pinMode(motorON, OUTPUT);
  pinMode(motorDir, OUTPUT);

  pinMode (es1, INPUT);
  pinMode (es2, INPUT);
  pinMode (es3, INPUT);

  pinMode (openDoorCmd, INPUT);


  Serial.begin (9600);
}


// the loop function runs over and over again forever
void loop() {

  if (digitalRead(es3) == 1) {
    Serial.println("I'm opening the door");
    turnLeft();
    delay(2000);
    turnRight();
    delay(2000);
    stopMotor();
  }
}


void turnRight() {
  digitalWrite(motorON, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(motorDir, LOW);
}

void turnLeft() {
  digitalWrite(motorON, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(motorDir, HIGH);
}

void stopMotor() {
  digitalWrite(motorON, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(motorDir, LOW);
}

