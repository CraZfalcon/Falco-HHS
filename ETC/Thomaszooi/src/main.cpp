#include <Adafruit_GFX.h>    // Core graphics library
#include <MCUFRIEND_kbv.h>   // Hardware-specific library
#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
MCUFRIEND_kbv tft;

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSans12pt7b.h>
#include <Fonts/FreeSerif12pt7b.h>

#include <FreeDefaultFonts.h>

#define BLACK   0x0000
#define RED     0xF800
#define GREEN   0x07E0
#define WHITE   0xFFFF
#define GREY    0x8410

static const uint32_t GPSBaud = 4800;

TinyGPSPlus gps;
SoftwareSerial ss(0, 1);

int COLOR;
int bg;
int msg;
int lager;
int x;

void setup(void)
{
    Serial.begin(9600);

      ss.begin(9600);

    uint16_t ID = tft.readID();
    Serial.println("Example: Font_simple");
    Serial.print("found ID = 0x");
    Serial.println(ID, HEX);
    if (ID == 0xD3D3) ID = 0x9481; //force ID if write-only display
    tft.begin(0x9341);
    tft.setRotation(135);

    int16_t x1, y1;
    uint16_t wid, ht;
    tft.fillScreen(TFT_BLACK);
    msg = 330;
    lager = 0;
    x = 0;
}

void loop(void)
{
  msg = int(gps.speed.kmph());
    { //Setup text aspects
      if(msg<10)x = 210;
      if(msg>=10 & msg<100)x = 102;
      if(msg>=100)x = -6;
      if(msg >119)COLOR = RED;
      else COLOR = GREEN;
      bg = BLACK;
    }
    { //Clear screen on less digits
      if(lager == 3 & msg < 100)tft.fillScreen(BLACK);
      if(lager == 2 & msg < 10)tft.fillScreen(BLACK);
    }
    { //Check speed range
      if(msg > 99)lager = 3;
      if(msg > 9 && msg < 100)lager = 2;
      if(msg >= 0 && msg < 10)lager = 1;
    }
    while (ss.available() > 0)
    if (gps.encode(ss.read()))
      showmsgXY(x, 50, 18, &FreeSevenSegNumFont); //Print Numbers
    //msg--;
    //delay(500);
}

void showmsgXY(int x, int y, int sz, const GFXfont *f)
{
    tft.setFont();
    tft.setCursor(x, y);
    tft.setTextColor(COLOR, bg);
    tft.setTextSize(sz);
    tft.print(msg);
    //tft.print(int(gps.speed.kmph()));
}