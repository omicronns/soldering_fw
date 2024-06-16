#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include <array>
#include <ui/components/textbox.hpp>
#include <ui/components/rect.hpp>
#include <ui/blocks/tool.hpp>

#define TFT_RST 12
#define TFT_DC 11
#define TFT_MOSI 10
#define TFT_SCLK 9
#define TFT_CS 8
#define TFT_BL 3

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void) {
  tft.initR(INITR_144GREENTAB);

  tft.fillScreen(ST7735_BLACK);

  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.setRotation(1);
}

UiTool tool{&tft, 32, 32};

void loop() {
  tool.process(millis());
  delay(100);
}
