
const int Echopinfrontale = 7;
const int TriggerPinfrontale = 6;
const int EchoPinsinistra = 11;
const int TriggerPinsinistra = 10;                                      //definizione ingressi Arduino
const int EchoPindestra = 9;
const int TriggerPindestra = 8;
const int motoresinistra1 = 2;
const int motoresinistra2 = 3;
const int motoredestra1 = 4;
const int motoredestra2 = 5;
volatile float massimadistanzafrontale = 25.00;
volatile float DurataFrontale, DistanzafrontaleCm, DurataSinistra, DistanzaSinistraCm, DurataDestra, DistanzadestraCm;
volatile float massimadistanzasinistra, massimadistanzadestra = 20.00;


void setup() {


  //sensori

  pinMode(TriggerPinfrontale, OUTPUT);    //definizione Input e Output sensori
  pinMode(Echopinfrontale, INPUT);
  pinMode(TriggerPinsinistra, OUTPUT);
  pinMode(EchoPindestra, INPUT);
  pinMode(TriggerPindestra, OUTPUT);
  pinMode(EchoPindestra, INPUT);

  // motori

  pinMode(motoresinistra1, OUTPUT);   //definizione Output motori
  pinMode(motoresinistra2, OUTPUT);
  pinMode(motoredestra1, OUTPUT);
  pinMode(motoredestra2, OUTPUT);
}
void loop() {

  //controllo distanza frontale

  checkDistanzaFrontale();
  if (DistanzafrontaleCm < massimadistanzafrontale) {      
    checkDistanzaSinistra();
    delay(20);
    checkDistanzaDestra();
    delay(20);
    if (DistanzaSinistraCm < DistanzadestraCm)
      muovitiaDestra();
    else if (DistanzaSinistraCm > DistanzadestraCm) {
      muovitiaSinistra();
    }
  }
  else {
    
    muovitiAvanti();
  }

  //controllo distanza a sinistra

  checkDistanzaSinistra();
  if (DistanzaSinistraCm < massimadistanzasinistra) {   
    delay(20);
    checkDistanzaSinistra();
    delay(20);
    checkDistanzaDestra();
    delay(20);
    if (DistanzaSinistraCm > DistanzadestraCm)
      muovitiAvanti();
    else if (DistanzaSinistraCm < DistanzadestraCm) {
      muovitiaDestra();
    }
  }

  //controllo distanza a destra

  checkDistanzaDestra();
  if (DistanzadestraCm < massimadistanzadestra) {     //comandi per monitor seriale
    delay(20);
    checkDistanzaDestra();
    delay(20);
    checkDistanzaSinistra();
    delay(20);
    if (DistanzadestraCm > DistanzaSinistraCm)
      muovitiAvanti();
    else if (DistanzadestraCm < DistanzaSinistraCm) {
      muovitiaSinistra();
    }
  }
}

//controllo distanze

void checkDistanzaFrontale() {
  digitalWrite(TriggerPinfrontale, LOW);
  delayMicroseconds(4);
  digitalWrite(TriggerPinfrontale, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinfrontale, LOW);
  DurataFrontale = pulseIn(Echopinfrontale, HIGH);
 
  
}
void checkDistanzaSinistra() {
  
  digitalWrite(TriggerPinsinistra, LOW);
  delayMicroseconds(4);
  digitalWrite(TriggerPinsinistra, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPinsinistra, LOW);
  DurataSinistra = pulseIn(EchoPinsinistra, HIGH);

}

void checkDistanzaDestra() {
  
  digitalWrite(TriggerPindestra, LOW);
  delayMicroseconds(4);
  digitalWrite(TriggerPindestra, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPindestra, LOW);
  DurataDestra = pulseIn(EchoPindestra, HIGH);

}

void muovitiIndietro() {                               //movimento motori indietro
  
  digitalWrite(motoresinistra1, HIGH);
  digitalWrite(motoresinistra2, LOW);
  digitalWrite(motoredestra1, HIGH);
  digitalWrite(motoredestra2, LOW);
}

void muovitiAvanti() {                                //movimento motori avanti
  
  digitalWrite(motoresinistra1, LOW);
  digitalWrite(motoresinistra2, HIGH);
  digitalWrite(motoredestra1, LOW);
  digitalWrite(motoredestra2, HIGH);
}

void muovitiaSinistra() {                                   //movimento motori sinistra
  
  digitalWrite(motoresinistra1, LOW);
  digitalWrite(motoresinistra2, HIGH);
  digitalWrite(motoredestra1, HIGH);
  digitalWrite(motoredestra2, LOW);
}

void muovitiaDestra() {                                  //movimento motori destra

  digitalWrite(motoresinistra1, HIGH);
  digitalWrite(motoresinistra2, LOW);
  digitalWrite(motoredestra1, LOW);
  digitalWrite(motoredestra2, HIGH);
}

