#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include <ui/elements/tool.hpp>

#define TFT_RST PA12
#define TFT_DC PA11
#define TFT_MOSI PA10
#define TFT_SCLK PA9
#define TFT_CS PA8
#define TFT_BL PA3

#define BTN_UP PA2
#define BTN_DN PA1
#define BTN_OK PA0

#define TEMP_CH1 PA6
#define TEMP_CH2 PA4

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

UiTool toolCH1{&tft, {32, 16}};
UiTool toolCH2{&tft, {32, 64}};
UiSchedule<2> ui{{&toolCH1, &toolCH2}};

void loop()
{
    toolCH1.setTemps(512, analogRead(TEMP_CH1));
    toolCH2.setTemps(256, analogRead(TEMP_CH2));
    ui.update();
    ui.process();
    delay(500);
}
