#include <Servo.h>
#include <ESP8266WiFi.h>
//#include "FirebaseESP8266.h"
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

//Set these to run example
#define FIREBASE_AUTH "ZiRafXEE0iqF4ZH4gF2psmr2x2VgVQ9SvKjrMP6f"
#define FIREBASE_HOST "poolmanagement-9ab24.firebaseio.com"
#define WIFI_SSID "Nadeesha"
#define WIFI_PASSWORD "12345678"

int trigpin1 = D0;
int echopin1 = D1;
int trigpin2 = D2;
int echopin2 = D3;
long duration1, cm1 , duration2, cm2;
int freeslots, maxslots = 3;

Servo servo1, servo2;

int count = 0;

//bool servo1.write(90) = true;
//bool servo2.write(90) = true;


void setup() {
  //for detect person

  Serial.begin(9600);
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);

  //for servor moter enterence

  servo1.attach(D4);
  servo1.write(0);



  servo2.attach(D5);
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



  if (count < maxslots) {

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

        freeslots = maxslots - count;
        Serial.print(freeslots);
        Serial.print(" Students can Enterd the Swimming Pool this Time ");
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

        freeslots = maxslots - count;
        Serial.print(freeslots);
        Serial.print(" Students can Enterd the Swimming Pool this Time ");
        Serial.println();



      }

      servo2.write(0);
      delay(2000);


    }


  }
  if (count >= maxslots) {
    Serial.print("The Swimming Pool is full In this Time ");
    Serial.println();
  }
  
//    freeslots = maxslots - count;
//    if (freeslots = maxslots) {
//      Serial.print("The Swimming Pool is Free In this Time ");
//      Serial.println();
//    }
//    else if (freeslots > 0) {
//      Serial.print(freeslots);
//      Serial.print(" Students can Enterd the Swimming Pool this Time ");
//      Serial.println();
//    }


}
