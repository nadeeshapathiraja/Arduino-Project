#include<SoftwareSerial.h>
#include "TinyGPS++.h"

SoftwareSerial ArduinoUno(3,2);
SoftwareSerial serial_connection(10,11);
TinyGPSPlus gps;
String f;

void setup() {
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
  ArduinoUno.begin(115200);

}

void loop() {
  while(serial_connection.available()){
    gps.encode(serial_connection.read());
  }
  
  if(gps.location.isUpdated())
  {
    f=String(gps.location.lat(),6)+","+String(gps.location.lng(),6);
    Serial.println(f);
    ArduinoUno.println(f);
    delay(20000); 
  }
  
  
}
