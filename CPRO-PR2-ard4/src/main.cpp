#include <Arduino.h>
#include <IRremote.h>
#include <ESP32Servo.h>

IRrecv irrecv(13);
Servo servo;
decode_results results;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  servo.attach(12);
}

void loop(){
  if (irrecv.decode(&results)){
    Serial.println(results.value);
    int serVal = map(results.value, 0, 1023, 0, 180);
    servo.write(serVal);
    irrecv.resume();
  }
  delay(100);
}