#include<Arduino.h>
/*leds
intledPins[]={5,6,7,8,9,10,11,12};

#defineRETURNLED

voidsetup(){

for(inti=0;i<9;i++){
pinMode(ledPins[i],OUTPUT);
}

}

voidloop(){

intl=8,r=9,i=0;

for(i;i<=3;i++){
digitalWrite(l-i,HIGH);
digitalWrite(r+i,HIGH);
delay(100);
digitalWrite(l-i,LOW);
digitalWrite(r+i,LOW);
}
#ifdefRETURNLED
for(i--;i!=-1;i--){
digitalWrite(l-i,HIGH);
digitalWrite(r+i,HIGH);
delay(100);
digitalWrite(l-i,LOW);
digitalWrite(r+i,LOW);
}
#endif

}*/

/*10.2langzaamterug*/

const int ledPins[] = {6,7,8,9,10,11,12,13};
const int analoogInPin = 0;
uint8_t aantalLEDs = sizeof(ledPins) / sizeof ledPins[0];

const boolean LED_AAN = LOW;
const boolean LED_UIT = HIGH;

int sensorWaarde = 0;
int ledNivo = 0;
int previousVolume = 0;

int lastCycle = 0;
int refreshInterval = 200;


void setup(){
  for(int led = 0; led < aantalLEDs; led++){
    pinMode(ledPins[led],OUTPUT);
  }
}

void ledScript(){
  sensorWaarde = analogRead(analoogInPin);

  ledNivo = map(sensorWaarde,0,1023,0,aantalLEDs+1);

  if (ledNivo < previousVolume) {
    ledNivo = max(ledNivo, previousVolume - 1);
  }

  for(int led=0; led < aantalLEDs; led++){
    if(led<ledNivo) {
      digitalWrite(ledPins[led],LED_AAN);
    }
    else{
      digitalWrite(ledPins[led],LED_UIT);
    }
  }
  previousVolume = ledNivo;
}

void loop(){
  if (millis() - lastCycle > refreshInterval) {
    ledScript();
    lastCycle += refreshInterval;
  }
}

