int pins[] = {6, 7, 4, 3, 2, 8, 9};

boolean numbers[10][7] = {

  {1, 1, 1, 1, 1, 1, 0},//0
  {0, 1, 1, 0, 0, 0, 0},//1
  {1, 1, 0, 1, 1, 0, 1},//2
  {1, 1, 1, 1, 0, 0, 1},//3
  {0, 1, 1, 0, 0, 1, 1},//4
  {1, 0, 1, 1, 0, 1, 1},//5
  {1, 0, 1, 1, 1, 1, 1},//6
  {1, 1, 1, 0, 0, 0, 0},//7
  {1, 1, 1, 1, 1, 1, 1},//8
  {1, 1, 1, 1, 0, 1, 1},//9

};

boolean anode = 0;
boolean cathode = 1;

//boolean mode = cathode;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop()
{
  for (int no = 0; no < 10; no++) {
    display(no, false);
    delay(1000);
    Serial.println(no);
  }
}
void display(int no, boolean dotv) {
  for (int i = 0; i < 7; i++) {
    if (numbers[no][i]) {
      digitalWrite(pins[i], 0);
    } else {
      digitalWrite(pins[i], 1);
    }
  }

  if (dotv) {
    digitalWrite(pins[7], 0);
  } else {
    digitalWrite(pins[7], 1);
  }
}
