#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

#define   TFT_DC 9
#define   TFT_CS 10

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);

void setup() {
  tft.begin();

  tft.setCursor(26, 120);
  tft.setTextColor(ILI9341_PINK);
  tft.setTextSize(3);
  tft.print("hello world");
  
}
void loop() {
  // put your main code here, to run repeatedly:

}
