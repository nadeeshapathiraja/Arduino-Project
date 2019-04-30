#include <Servo.h>

int trigpin1 = 11;
int echopin1 = 12;
int trigpin2 = 10;
int echopin2 = 8;
long duration1, cm1 , duration2, cm2;

Servo servo1, servo2;

int count = 0;

//bool servo1.write(90) = true;
//bool servo2.write(90) = true;


void setup() {
  //for detect person
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);

  //for servor moter enterence

  servo1.attach(6);
  servo1.write(0);



  servo2.attach(3);
  servo2.write(0);

  Serial.begin (9600);

  digitalWrite(trigpin1, LOW);
  delayMicroseconds(5);

  digitalWrite(trigpin2, LOW);
  delayMicroseconds(5);


}

void loop() {

  delay(500);

  digitalWrite(trigpin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin1, LOW);

  duration1 = pulseIn(echopin1, HIGH);

  cm1 = (duration1 / 2) / 29.1;

  Serial.print(duration1);
  Serial.print(",");

  Serial.print(cm1);
  Serial.print("cm-1 ");
  Serial.println();



  if (count < 3) {//10 is the maximunm student count

    if (cm1 <= 50) {
      Serial.println("Sensor Detect the person in Front");


      delay(50);          // wait for sensors to stabilize
      servo1.write(90);
      delay(3000);//servo moter aka pallehata ena aka ta kalaya(Uda redila tina)
      if (cm1 <= 50) {
        count += 1;
        Serial.print(count);
        Serial.print("Students In this Time ");
        Serial.println();
      }

      servo1.write(0);
      delay(2000);

    }
  }



  delay(500);

  digitalWrite(trigpin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin2, LOW);

  duration2 = pulseIn(echopin2, HIGH);

  cm2 = (duration2 / 2) / 29.1;

  Serial.print(duration2);
  Serial.print(",");

  Serial.print(cm2);
  Serial.print("cm-2 ");
  Serial.println();


  //Studentsla akkenk ho ita wada pool ake innawanm witari meka weda karanne
  if (count > 0) {
    if (cm2 <= 50) {
      Serial.println("Sensor Detect the person in Back");


      delay(50);          // wait for sensors to stabilize
      servo2.write(90);
      delay(3000);//servo moter aka pallehata ena aka ta kalaya(Uda redila tina)
      if (cm2 <= 50) {
        count -= 1;
        Serial.print(count);
        Serial.print("Students In this Time ");
        Serial.println();
      }

      servo2.write(0);
      delay(2000);




    }
  }

  if (count >= 3) {
    Serial.print("Students full In this Time ");
    Serial.println();
  }






}
