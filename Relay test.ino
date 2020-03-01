//A simple code for relays test

#define RELAY1 2
#define RELAY2 3

void setup() {

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

}

void loop() {

  digitalWrite(RELAY1, LOW);
  delay(2000);
  digitalWrite(RELAY1, HIGH);
  
  digitalWrite(RELAY2, LOW);
  delay(2000);
  digitalWrite(RELAY2, HIGH);
  
}
