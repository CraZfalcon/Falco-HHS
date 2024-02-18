int DATA_IO = 8;   // SDI poort van MFS
int CLK_IO = 7;    // SFTCLK van MFS
int LATCH_IO = 4;  // LCHCLK van MFS
int teller = 0;

// Letters en cijfers in hexadecimaal
const int8_t LetterA = 0x77;   // 0111 0111 dp g f e   d c b a
const int8_t LetterB = 0x7F;   // 0111 1111 dp g f e   d c b a
const int8_t LetterC = 0x39;   // 0011 1001 dp g f e   d c b a
const int8_t LetterE = 0x79;   // 0111 1001 dp g f e   d c b a
const int8_t LetterF = 0x71;   // 0111 0001 dp g f e   d c b a
const int8_t Number9 = 0x3F;   // 0011 1111 dp g f e   d c b a
const int8_t LetterH = 0x76;   // 0111 0110 dp g f e   d c b a
const int8_t LetterI = 0x06;   // 0000 0110 dp g f e   d c b a
const int8_t LetterL = 0x38;   // 0011 1000 dp g f e   d c b a
const int8_t LetterO = 0x3F;   // 0011 1111 dp g f e   d c b a
const int8_t LetterP = 0x73;   // 0111 0011 dp g f e   d c b a
const int8_t LetterS = 0x6D;   // 0110 1101 dp g f e   d c b a
const int8_t LetterU = 0x3E;   // 0011 1110 dp g f e   d c b a
const int8_t LetterY = 0x6E;   // 0110 1110 dp g f e   d c b a
const int8_t SPACE = 0xFF;     // 1111 1111 dp g f e   d c b a

// Definieer segment selectie en eerste data
int8_t SEGMENT2Write = 0;
int8_t SEGMENT_SELECT[] = {0xF1, 0xF2, 0xF4, 0xF8}; // codes voor selectie vier segmenten van links naar rechts
int8_t SEGMENT_CONTENT[] = {0, 0, 0, 0}; // Initialiseren met lege data

void shiftOut(int8_t Data)
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

void WriteDataToSegment(int8_t Segment, int8_t Patroon)
{
  digitalWrite(CLK_IO, HIGH);
  digitalWrite(LATCH_IO, LOW);
  shiftOut(SEGMENT_SELECT[Segment]);
  shiftOut(SEGMENT_CONTENT[Patroon]);
  digitalWrite(LATCH_IO, HIGH);
}

void ToonNummer(int Number2Display)
{
  uint8_t duizendtal, honderdtal, tiental;
  duizendtal = Number2Display / 1000;
  SEGMENT_CONTENT[0] = duizendtal;
  Number2Display -= duizendtal * 1000;
  honderdtal = Number2Display / 100;
  SEGMENT_CONTENT[1] = honderdtal;
  Number2Display -= honderdtal * 100;
  tiental = Number2Display / 10;
  SEGMENT_CONTENT[2] = tiental;
  Number2Display -= tiental * 10;
  SEGMENT_CONTENT[3] = Number2Display;
}

void setup()
{
  pinMode(DATA_IO, OUTPUT);
  pinMode(CLK_IO, OUTPUT);
  pinMode(LATCH_IO, OUTPUT);
}

void loop()
{
  const int teksten_en_getallen[][4] = {
    {LetterA, LetterB, LetterC, SPACE},
    {LetterE, LetterF, Number9, SPACE},
    {LetterH, LetterI, LetterL, LetterO},
    {LetterP, LetterS, LetterU, LetterY}
  };

  for (int i = 0; i < sizeof(teksten_en_getallen) / sizeof(teksten_en_getallen[0]); i++)
  {
    for (uint8_t j = 0; j < 4; j++)
    {
      SEGMENT_CONTENT[j] = teksten_en_getallen[i][j];
    }

    for (uint8_t j = 0; j < 4; j++)
    {
      WriteDataToSegment(j, j);
    }

    delay(1000); // Wacht 1 seconde
  }
}
