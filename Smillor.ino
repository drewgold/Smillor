#include <Servo.h>
Servo servo1;
Servo servo2;
float degreesToMove1;
float degreesToMove2;

int sensorValue0;
int sensorValue1;
int sensorValue2;
int sensorValue3;

void setup() {
  Serial.begin(9600);
  servo1.attach(8);
  servo2.attach(9);
}

void loop() {
  int tolerance = 1;
  //Values are Integer values from 0 to 1023
  sensorValue0 = analogRead(A0);
  sensorValue1 = analogRead(A1);
  sensorValue2 = analogRead(A2);
  sensorValue3 = analogRead(A3);

  if(abs(sensorValue0-sensorValue2) > tolerance) {
    degreesToMove1 = ((sensorValue0-sensorValue2) / 1023) * 180;
    moveServo(servo1, degreesToMove1);
  }

  printData();
}
void moveServo(Servo servo, int deg) {
  int currentSetting = servo.read();
  int newSetting = currentSetting + deg;
  servo.write(deg);
}

void printData() {
  Serial.print("S0: ");
  Serial.print(sensorValue0);
  Serial.print(" S1: ");
  Serial.print(sensorValue1);
  Serial.print(" Difference: ");
  Serial.print(degreesToMove1);
  Serial.print(" Servo 1 Position: ");
  Serial.print(servo1.read());
  Serial.print("S2: ");
  Serial.print(sensorValue2);
  Serial.print(" S3: ");
  Serial.print(sensorValue3);
  Serial.print(" Difference: ");
  Serial.print(degreesToMove2);
  Serial.print(" Servo 1 Position: ");
  Serial.print(servo2.read());
 
  }
