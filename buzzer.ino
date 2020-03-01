//simple code that includes a buzzer


int buzzer=9;

void setup() {

  pinMode(buzzer, OUTPUT);

}

void loop() {

  tone(buzzer,1000,200);
  delay(2000);
  noTone(buzzer);
  delay(100);

}
