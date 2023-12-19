#include <Arduino.h>

int ledPos = 0;
unsigned long actueleTijd;
unsigned long cyclusTijd;
const int pin_A = 2; // Encoder CLK
const int pin_B = 3; // Encoder DT
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_vorige = 0;

void setup()  {
  Serial.begin(9600);
  DDRB = B11111111;
  PORTB = B00000001;
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  actueleTijd = millis();
  cyclusTijd = actueleTijd; 
}

void EncoderLoop(){
  encoder_A = digitalRead(pin_A);
  encoder_B = digitalRead(pin_B);
  if((!encoder_A) && (encoder_A_vorige)){
    if(encoder_B) if((ledPos + 1 <= 5)){ PORTB = PORTB << 1 ; ledPos++; }
    else if(ledPos - 1 >= 0){ PORTB = PORTB >> 1; ledPos--; }
  }
  encoder_A_vorige = encoder_A;
}

void loop()  {
  actueleTijd = millis();
  if(actueleTijd >= (cyclusTijd + 5)){  
    EncoderLoop();
    cyclusTijd = actueleTijd;
  }
  if(millis() % 1000 == 0){
    Serial.println("\n\n\n\n");
    Serial.println(ledPos);
    Serial.println(PORTB);
  }
}


/*
#include <Arduino.h>

int helderheid = 120;                                                                               // helderheid van de LED; start op halve helderheid
int stapHelderheid = 10;                                                                            // stapgrootte in helderheid van de LED
unsigned long actueleTijd;
unsigned long cyclusTijd;
const int pin_A = 2;                                                                                // pin 2 de CLK aansluiting van de Rotary encoder
const int pin_B = 3;                                                                                // pin 3 De DT aansluiting van de Rotary encoder
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_vorige = 0;

void setup()  {
  pinMode(9, OUTPUT);
  pinMode(pin_A, INPUT);
  pinMode(pin_B, INPUT);
  actueleTijd = millis();
  cyclusTijd = actueleTijd; 
} 

void loop()  {
  actueleTijd = millis();
  if(actueleTijd >= (cyclusTijd + 5)){                                                              // 5ms sinds de laatste test van de encoder = 200Hz  
    encoder_A = digitalRead(pin_A);
    encoder_B = digitalRead(pin_B);
    if((!encoder_A) && (encoder_A_vorige)){                                                         // A is van hoog naar laag gegaan 
      if(encoder_B) {                                                                               // B is hoog, dus de encoder is "met de klok mee" (naar rechts) gedraaid
        if(helderheid + stapHelderheid <= 255) helderheid += stapHelderheid;
      }
      else {
        if(helderheid - stapHelderheid >= 0) helderheid -= stapHelderheid;
      }                                                                                             // B is laag, dus de encoder is "tegen de klok in" (naar links) gedraaid
    }
    encoder_A_vorige = encoder_A;                                                                   // Sla de waarde van A op voor de volgende keer    
    analogWrite(9, helderheid);

    cyclusTijd = actueleTijd;                                                                       // actualiseer de cyclusTijd
  }
}
*/