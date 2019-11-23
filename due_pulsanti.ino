#include <Wire.h>

#define int_avanti 9
#define mot_avanti 10
#define int_indietro 11
#define mot_indietro 12
#define int_buzzer 8
#define buzzer 13

void setup() {
  pinMode(int_avanti, INPUT);
  pinMode(mot_avanti, OUTPUT);
  pinMode(int_indietro, INPUT);
  pinMode(mot_indietro, OUTPUT);
  pinMode(int_buzzer, INPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {

  int Ia = digitalRead(int_avanti);
  int Is = digitalRead(int_indietro);
  int Ib = digitalRead(int_buzzer);

  digitalWrite(mot_avanti, LOW);
  digitalWrite(mot_indietro, LOW);
  

  if(Ia == true && Is == false && Ib == false) {

    digitalWrite(mot_avanti, HIGH);
  }


else {

   digitalWrite(mot_avanti, LOW);
}


if(Ia == false && Is == true && Ib == false) {

  digitalWrite(mot_indietro, HIGH);
}


else {

  digitalWrite(mot_indietro, LOW);
  
}

if(Ib == true && Is == false && Ia == false) {

  tone(buzzer,1000,200);
  
}

}
