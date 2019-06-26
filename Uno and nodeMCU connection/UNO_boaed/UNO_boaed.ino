#include <SoftwareSerial.h>
SoftwareSerial s(2,3);
void setup() {

  s.begin(9600);

}

void loop() {
  int maxcount=10;
  int freeslots=7;
  int count=3;
  if(s.available()>0){
    char c=s.read();
    if(c=='s'){
      s.write(maxcount);
      s.write(freeslots);
      s.write(count);
      
    }
  }

  

}
