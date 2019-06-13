//FirebaseESP8266.h must be included before ESP8266WiFi.h
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <SoftwareSerial.h>

#define FIREBASE_AUTH "aOjMQB8rgonrUAvynErDU5Nts2gqUIi4aZhCQQhp"
#define FIREBASE_HOST "https://poolmanager-69be5.firebaseio.com"
#define WIFI_SSID "Nadeesha"
#define WIFI_PASSWORD "1231231234567"

//Define FirebaseESP8266 data object
FirebaseData firebaseData;

void setup()
{

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  //Set database read timeout to 1/2 minute (max 15 minutes)
  Firebase.setReadTimeout(firebaseData, 1000 * 30);
  //tiny, small, medium, large and unlimited.
  //Size and its write timeout e.g. tiny (1s), small (10s), medium (30s) and large (60s).
  Firebase.setwriteSizeLimit(firebaseData, "tiny");

  String path = "/Student Count";

  String jsonStr = "";

  Serial.println("------------------------------------");
  Serial.println("Set Firebase And Project Connection...");




}

int n = 0; 
 
void loop() { 
  // handle error 
  if (Firebase.failed()) { 
      Serial.print("setting /number failed:"); 
      Serial.println(Firebase.error());   
      return; 
  } 
  delay(1000); 
   
  
}
