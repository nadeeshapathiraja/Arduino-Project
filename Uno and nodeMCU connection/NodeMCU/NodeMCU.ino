#include <SoftwareSerial.h>
SoftwareSerial s(D3,D2);
int data;

void setup() {
  s.begin(9600);
  Serial.begin(9600);
}

void loop() {

  s.write("s");

  if(s.available()>0){
    data=s.read();
    Serial.println(data);
    delay(500);
  }

}
