int DATA_IO = 8;  // SDI poort van MFS
int CLK_IO = 7;  // SFTCLK van MFS
int LATCH_IO = 4; // LCHCLK van MFS
int teller = 0;

//Letters en cijfers in hexadecimaal
const int8_t LetterH = 0x89;    //1000 1001 dp g f e   d c b a
const int8_t LetterS = 0x92;    //1001 0010 dp g f e   d c b a
const int8_t LetterE = 0x86;    //1000 0110 dp g f e   d c b a
const int8_t LetterL = 0xC7;    //1100 0111 dp g f e   d c b a
const int8_t LetterC = 0xC6;    //1100 0110 dp g f e   d c b a
const int8_t SPACE = 0xFF;      //1111 1111 dp g f e   d c b a

const int8_t NUMBERS[] = { 0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90 };
//                          '0'   '1'   '2'   '3'   '4'   '5'   '6'   '7'   '8'   '9'
//Definieer segment selectie en eerste data
int8_t SEGMENT2Write = 0;
int8_t SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8}; // codes voor selectie vier segmenten van links naar rechts
int8_t SEGMENT_CONTENT[] = {0xC8, 0xC6, 0xC0, 0xF9}; // zet standaard "HHC " op display
int8_t RECEIVE_BUF[] = {0xFF, 0xFF, 0xFF, 0xFF}; // zet standaard ontvangbuffer leeg
int8_t TEKST_HHC[] = {0xC8, 0xC6, 0xC0, 0xF9}; // zet HHC op display
int8_t TEKST_ERROR[] = {0x8E, 0xA3, 0xE3, 0x87 }; // zet "Fout" op display
int8_t TEKST_GOED[] = {0x82, 0xC0, 0x86, 0xA1 }; // zet "GOEd" op display

//Converteer een nummer naar een ruwe data voor het shiftregister op het 7-segments display
void shiftOut( int8_t Data)
{
  int8_t j;
  for (j = 0; j < 8; j++)
  {
    if (Data & 0x80)
      digitalWrite(DATA_IO, HIGH);
    else
      digitalWrite(DATA_IO, LOW);
    digitalWrite(CLK_IO, LOW);
    Data = Data << 1;
    digitalWrite(CLK_IO, HIGH);
  }
}

//Besturen van het schuifregister
void WriteDataToSegment(int8_t Segment, int8_t Patroon)
{
  digitalWrite(CLK_IO, HIGH);
  digitalWrite( LATCH_IO, LOW);
  shiftOut(SEGMENT_CONTENT[Patroon]);
  shiftOut(SEGMENT_SELECT[Segment]);
  digitalWrite( LATCH_IO, HIGH);
}

//Bepaal segmentnummer op basis van getalgrootte
void ToonNummer( int Number2Display) {
  uint8_t duizendtal, honderdtal, tiental;
  duizendtal = Number2Display / 1000;
  SEGMENT_CONTENT[0] = NUMBERS[duizendtal];
  Number2Display -= duizendtal * 1000;
  honderdtal = Number2Display / 100;
  SEGMENT_CONTENT[1] = NUMBERS[honderdtal];
  Number2Display -= honderdtal * 100;
  tiental = Number2Display / 10;
  SEGMENT_CONTENT[2] = NUMBERS[tiental];
  Number2Display -= tiental * 10;
  SEGMENT_CONTENT[3] = NUMBERS[Number2Display];

}

void setup()
{
  pinMode( DATA_IO, OUTPUT);
  pinMode( CLK_IO, OUTPUT);
  pinMode( LATCH_IO, OUTPUT);
}
void loop()
{
  teller++;

  if (teller < 1000) {
    SEGMENT_CONTENT[0] = LetterH;
    SEGMENT_CONTENT[1] = LetterH;
    SEGMENT_CONTENT[2] = LetterS;
    SEGMENT_CONTENT[3] = SPACE;
  }
  else {
    if (teller > 2000) teller = 0;
    SEGMENT_CONTENT[0] = LetterE;
    SEGMENT_CONTENT[1] = LetterL;
    SEGMENT_CONTENT[2] = LetterE;
    SEGMENT_CONTENT[3] = LetterC;
  }

  for (uint8_t i = 0; i < 4; i++) {
    WriteDataToSegment(i, i);
  }
  delay(1);  // als delay dan laatste segment feller omdat die langer aangestuurd wordt.
}
