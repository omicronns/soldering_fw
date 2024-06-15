#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#define TFT_RST 12
#define TFT_DC 11
#define TFT_MOSI 10
#define TFT_SCLK 9
#define TFT_CS 8
#define TFT_BL 3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  tft.initR(INITR_144GREENTAB);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.setRotation(1);
  tft.fillRect(0, 0, 128, 128, tft.color565(255, 0, 0));
  tft.fillRect(0, 0, 64, 64, tft.color565(0, 255, 0));
  tft.fillRect(64, 64, 64, 64, tft.color565(0, 0, 255));
  tft.setTextColor(tft.color565(0, 0, 0));
  tft.setCursor(0, 0);
  tft.print("test");
}

void loop() {
  // tft.invertDisplay(true);
  // delay(500);
  // tft.invertDisplay(false);
  // delay(500);
}
