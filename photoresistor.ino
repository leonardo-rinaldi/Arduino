#define fotoresistenza A1
#define led 12
void setup()
{
 pinMode(A1,INPUT);
 pinMode(12,OUTPUT);
 Serial.begin(9600); // Inizializzo la comunicazione seriale
}

void loop()
{
 int val = analogRead(fotoresistenza); // salvo il valore fotoresistenza dentro alla variabile val
 Serial.println(val, DEC); // Scrivo il valore della fotoresistenza, espresso in numeri decimali
 
 if(val<200) //se il valore letto dalla fotoresistenza (luminosità) è basso, accendo il led
 digitalWrite(led,HIGH);
 else
 digitalWrite(led,LOW); //altrimenti lo spengo (o lo lascio spento)
 
}
