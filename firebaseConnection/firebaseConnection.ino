#include <ESP8266WiFi.h>
//#include "FirebaseESP8266.h"
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

//Set these to run example
#define FIREBASE_AUTH "ZiRafXEE0iqF4ZH4gF2psmr2x2VgVQ9SvKjrMP6f"
#define FIREBASE_HOST "poolmanagement-9ab24.firebaseio.com"

#define WIFI_SSID "Nadeesha"
#define WIFI_PASSWORD "1231231234567"

void setup() {

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected:");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  if (Firebase.failed())
  {
    Serial.print("setting number failed:");
    Serial.println(Firebase.error());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    delay(2000);
    return;
  }
  
 Firebase.setFloat("person/xsshdhsa/name",12.006);
  delay(10000);
  Serial.println("Hellow");
}
