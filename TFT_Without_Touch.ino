#include <Adafruit_GFX.h>
#include <TFT Touch Sheild.h>
 
#define BLACK 0x0000
#define WHITE 0xFFFF
 
MCUFRIEND_kbv tft;

void setup() {
  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.fillScreen(BLACK);
  tft.setCursor(10, 10);
  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.print("Hello, Arduino!");
}

void loop() {}