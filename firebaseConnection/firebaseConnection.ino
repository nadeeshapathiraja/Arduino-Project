#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
//#include <SoftwareSerial.h>
//#include <ArduinoJson.h>
//#include <ESP8266HTTPClient.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

//Set these to run example
#define FIREBASE_HOST "https://groupproject-15de4.firebaseio.com"
#define FIREBASE_AUTH "6mUhtevPAsjIpfev2NS6ObC2ss2nfMsusMGlwghn"

//
#define WIFI_SSID "Nadeesha"
#define WIFI_PASSWORD "pdnc12345"




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

void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  if (Firebase.failed())
  {
    Serial.print("setting number failed:");
    Serial.println(Firebase.error());
    firebasereconnect();
    delay(1000);
    return;
  }
  
  Firebase.setString("location","Nadeesha");
}
