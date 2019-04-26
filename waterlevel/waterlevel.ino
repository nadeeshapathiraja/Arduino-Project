#define trig 2
#define echo 4

void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(8,OUTPUT);

}

void motoron(){
  digitalWrite(8,LOW);
}

void motoroff (){ 
  digitalWrite(8,HIGH);
}

void loop() {
  int height=150;
  int offlevel=20;

  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);

  long t = pulseIn(echo,HIGH);
  long cm = t/29/2;

  int onlevel=height*3/4+offlevel;
  
  if(cm>onlevel){
    motoron();  
  }
  else{
    if(cm<offlevel){
        motoroff();
    }
  }
  delay(100);
}





