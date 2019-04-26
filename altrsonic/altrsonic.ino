#include <Servo.h>
int trigpin = 11;
int echopin = 12;
long duration, cm, inches;
Servo servo;
int count = 0;


void setup() {
  //for detect person
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);

  //for servor moter
  //pinMode(9,OUTPUT);
  servo.attach(9);
  servo.write(0);

  Serial.begin (9600);

  digitalWrite(trigpin, LOW);
  delayMicroseconds(5);


}

void loop() {
  delay(500);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);

  cm = (duration / 2) / 29.1;
  inches = (duration / 2) / 74;

  Serial.print(duration);
  Serial.print(",");

  Serial.print(cm);
  Serial.print("cm,");

  Serial.print(inches);
  Serial.print("Inches");
  Serial.println();

  if (cm <= 50) {
    Serial.println("Sensor Detect the person");

    do
    {
      delay(50);          // wait for sensors to stabilize
      servo.write(90);
      delay(2000);

      servo.write(0);
      delay(2000);

    } while (cm <= 50);


  }



}
