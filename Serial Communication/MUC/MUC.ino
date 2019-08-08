#include <SoftwareSerial.h>
SoftwareSerial s(D6,D5);
#include <ArduinoJson.h>
 
void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  s.begin(115200);
  while (!Serial) continue;
}
 
void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
 
  if (root == JsonObject::invalid())
  {
    return;
  }
  Serial.print("gas sensor  ");
  int data4=root["gasv"];
  Serial.println(data4);
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");
 Serial.println("");
}
