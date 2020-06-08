/*
 * Questo è un semplicissimo esempio di utilizzo della PWM (Pulse With Modulation)
 * per variare la luminosità di un led.
 * Il valore massimo per la PWM è 255, il valore minimo è 0.
 * 
 */

#include <Wire.h>

#define led 5

void setup() {

  pinMode(led, OUTPUT);

}

void loop() {

    /*
     * Vario la luminosità del led
     */

    analogWrite(led, 255);
    delay (1000);
    analogWrite(led, 100);
    delay (1000);
    analogWrite(led, 50);
    delay (1000);
    analogWrite(led, 10);
    delay(1000);



}
