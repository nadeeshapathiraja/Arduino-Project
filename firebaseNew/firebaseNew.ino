#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

//Set these to run example
#define FIREBASE_HOST "poolmanager-69be5.firebaseio.com"
#define FIREBASE_AUTH "aOjMQB8rgonrUAvynErDU5Nts2gqUIi4aZhCQQhp"
#define WIFI_SSID "Nadeesha"
#define WIFI_PASSWORD "123456123"



void setup() {

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting..");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("WiFi Connected!!!");
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
 Firebase.setFloat("studentCount/maxCount",5);
 Firebase.setFloat("studentCount/freeSlots",2);
 Firebase.setFloat("studentCount/count",4);
  delay(10000);
  Serial.println("Data Send To Firebase");
}
