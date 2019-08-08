#define trig 2
#define echo 4

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(8,OUTPUT);
  delay(5000);

}

void motoron(){
  digitalWrite(8,LOW);
}

void motoroff (){ 
  digitalWrite(8,HIGH);
}

void loop() {
  int height=50;
  int offlevel=20;

  digitalWrite(trig,LOW);
  delayMicroseconds(5);
  digitalWrite(trig,HIGH);
  delayMicroseconds(20);

  long t = pulseIn(echo,HIGH);
  long cm = t/29/2;

  int onlevel=40+offlevel;

  
  
  
  if(cm>onlevel){
    motoron(); 
    Serial.print("The Moter is ON "); 
  }
  else{
    if(cm<offlevel){
        motoroff();
        Serial.print("The Moter is OFF ");
    }
  }
  delay(1000);
}
