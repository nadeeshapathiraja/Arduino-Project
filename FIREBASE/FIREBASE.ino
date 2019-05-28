#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>

// Set these to run example.
#define FIREBASE_HOST "vehicletrackinsystem.firebaseio.com"
#define FIREBASE_AUTH "Yy9Blaj6oxgBCo7QXKpABB8PrtNZFRN5zD4Dq0Mt"
#define WIFI_SSID "TheHacker"
#define WIFI_PASSWORD "leavemealone"

SoftwareSerial NodeMCU(D2,D3);

void setup() {
  Serial.begin(9600);
  NodeMCU.begin(115200);
  pinMode(D2,INPUT);
  pinMode(D3,OUTPUT);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("WiFi Connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
void loop() {
  // handle error
//  if (Firebase.failed()) {
//     Serial.print("setting /location failed:");
//     Serial.println(Firebase.error());
//     delay(2000);  
//     return;
//     
//   }
  String content="";
  char character;
  while(NodeMCU.available()>0){
    character=NodeMCU.read();
    content.concat(character);
  }
  if(content!=""){
    Serial.print("\nLatitude : ");
    Serial.print(content.substring(0,8));
    Serial.print("\nLongitude :");
    Serial.print(content.substring(9,18));
    //set value
    Firebase.setString("Location",content.substring(0,8)+","+
    content.substring(9,18));
  }
  
  delay(2000); 
}
