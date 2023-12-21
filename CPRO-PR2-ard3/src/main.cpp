#include<Arduino.h>

int DATA_IO = 8;//SDIpoortvanMFS
int CLK_IO = 7;//SFTCLKvanMFS
int LATCH_IO = 4;//LCHCLKvanMFS
int teller = 0;

const int LetterF = 0x8E;
const int LetterA = 0x88;
const int LetterL = 0xC7;
const int LetterC = 0xC6;

//    int LetterA = 0x88;
const int LetterR = 0xAF;
const int LetterD = 0xA1;
const int LetterU = 0xE3;

const int SPACE = 0xFF;          //11111111 dp g f e d c b a // 11100011

// afge 10001110

const int NUMBERS[]= {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
                            //’0’’1’’2’’3’’4’’5’’6’’7’’8’’9’
//Definieersegmentselectieeneerstedata
int SEGMENT2Write = 0;
int SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
int SEGMENT_CONTENT[] = {0x89,0x89,0x92,0xFF};//”HHC”opdisplay

//Converteereennummernaareenruwedatavoorhetshiftregister
//ophet7−segmentsdisplay
void shiftOut(int Data){
  for(int j = 0; j < 8; j++){
    if(Data&0x80)
      digitalWrite(DATA_IO,HIGH);
    else
      digitalWrite(DATA_IO,LOW);
    digitalWrite(CLK_IO,LOW);
    Data=Data<<1;
    digitalWrite(CLK_IO,HIGH);
  }
}

//Besturenvanhetschuifregister
void WriteDataToSegment(int Segment,int Patroon){
  digitalWrite(CLK_IO,HIGH);

  digitalWrite(LATCH_IO,LOW);
  shiftOut(SEGMENT_CONTENT[Patroon]);
  shiftOut(SEGMENT_SELECT[Segment]);
  digitalWrite(LATCH_IO,HIGH);
}

void ToonNummer(int Number2Display){
  int duizendtal,honderdtal,tiental;
  duizendtal = Number2Display / 1000;
  SEGMENT_CONTENT[0]=NUMBERS[duizendtal];
  Number2Display-= duizendtal * 1000;
  honderdtal = Number2Display / 100;
  SEGMENT_CONTENT[1] = NUMBERS[honderdtal];
  Number2Display-= honderdtal * 100;
  tiental = Number2Display / 10;
  SEGMENT_CONTENT[2] = NUMBERS[tiental];
  Number2Display-= tiental * 10;
  SEGMENT_CONTENT[3] = NUMBERS[Number2Display];
}

void ToonNummerBeter(int Number2Display){ //mislukt
  SEGMENT_CONTENT[0]=NUMBERS[(Number2Display)%1000];
  SEGMENT_CONTENT[1]=NUMBERS[(Number2Display - ((Number2Display%1000)*1000))%100];
  SEGMENT_CONTENT[2]=NUMBERS[(Number2Display - ((((Number2Display%1000)*1000))%100)*100)%10];
  SEGMENT_CONTENT[3]=NUMBERS[(Number2Display - ((((((Number2Display%1000)*1000))%100)*100)%10)*10)];
  //SEGMENT_CONTENT[2]=NUMBERS[(Number2Display)%10];
  //SEGMENT_CONTENT[3]=NUMBERS[(Number2Display)];
}

void setup(){
  pinMode(DATA_IO,OUTPUT);
  pinMode(CLK_IO,OUTPUT);
  pinMode(LATCH_IO,OUTPUT);
}
void loop(){
  teller++;

  if(teller<1000){
    SEGMENT_CONTENT[0]=LetterF;
    SEGMENT_CONTENT[1]=LetterA;
    SEGMENT_CONTENT[2]=LetterL;
    SEGMENT_CONTENT[3]=LetterC;
  }
  else{
    if(teller>2000) teller=0;
    SEGMENT_CONTENT[0]=LetterA;
    SEGMENT_CONTENT[1]=LetterR;
    SEGMENT_CONTENT[2]=LetterD;
    SEGMENT_CONTENT[3]=LetterU;
  }

  for(int i = 0; i < 4; i++){
    WriteDataToSegment(i,i);
  }
  //delay(1);
}


