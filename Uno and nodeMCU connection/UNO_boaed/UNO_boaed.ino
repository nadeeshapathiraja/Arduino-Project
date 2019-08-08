/*
 * bismillah hir rahman nir raheem
 * UNO/Nano = Pin 7 & Pin 8
 * Note: Uno and ESP8266 cross connection
 */

#include <SoftwareSerial.h>
SoftwareSerial ArduinoUno(7,8);

String f;

void setup(){

        Serial.begin(9600);

    ArduinoUno.begin(115200);

}
void loop(){

  float i = (random(100) + 1);

  float j = (random(100) + 1);

 f = String('H')+String(i)+String('T')+String(j); 

  ArduinoUno.println(f);

delay(2000);
}
