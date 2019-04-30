#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

//#include <SoftwareSerial.h>
//#include <ArduinoJson.h>
//#include <ESP8266HTTPClient.h>

//Set these to run example
#define FIREBASE_HOST "https://stucount-12793.firebaseio.com/"
#define FIREBASE_AUTH "s15vUwxpXpcwUVjzqpjlgszjuHXlsTwVQMsczQd7"
#define WIFI_SSID "swimmingclub"
#define WIFI_PASSWORD "kccswimming"




void setup() {

  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
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
    return;
  }
}
