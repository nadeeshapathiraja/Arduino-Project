#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(5, 6);


void setup() {
  s.begin(115200);
  pinMode(A0, INPUT);

}
StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

void loop() {

  root["gasv"] = analogRead(A0);

  if (s.available() > 0)
  {
    root.printTo(s);
  }
}
