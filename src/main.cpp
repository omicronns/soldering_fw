#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include <ui/components/textbox.hpp>
#include <ui/components/rect.hpp>
#include <ui/blocks/tool.hpp>

#define TFT_RST PA12
#define TFT_DC PA11
#define TFT_MOSI PA10
#define TFT_SCLK PA9
#define TFT_CS PA8
#define TFT_BL PA3

#define BTN_UP PA2
#define BTN_DN PA1
#define BTN_OK PA0

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void)
{
    tft.initR(INITR_144GREENTAB);

    tft.fillScreen(ST7735_BLACK);

    pinMode(BTN_UP, INPUT);
    pinMode(BTN_DN, INPUT);
    pinMode(BTN_OK, INPUT);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    tft.setRotation(1);
}

UiTool tool{&tft, 32, 32};

void loop()
{
    tool.process();
    delay(100);
    if (digitalRead(BTN_UP) == 0)
    {
        tool.setText("UP");
    }
    else if (digitalRead(BTN_DN) == 0)
    {
        tool.setText("DN");
    }
    else if (digitalRead(BTN_OK) == 0)
    {
        tool.setText("OK");
    }
}
