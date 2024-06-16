#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

#include <ui/widgets/tool.hpp>
#include <ui/objects/rect.hpp>

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

Adafruit_ST7735 gfx = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

void setup(void)
{
    gfx.initR(INITR_144GREENTAB);

    gfx.fillScreen(ST7735_BLACK);

    pinMode(BTN_UP, INPUT);
    pinMode(BTN_DN, INPUT);
    pinMode(BTN_OK, INPUT);
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH);

    gfx.setRotation(1);
}

UiTool toolCH1{&gfx, {32, 16}};
UiTool toolCH2{&gfx, {32, 64}};
UiRect rect{&gfx, {0, 0, 128, 128}, color565(0, 0, 0)};
UiSchedule<2> ui_main{{&toolCH1, &toolCH2}, true};
UiSchedule<1> ui_menu{{&rect}, true};
UiProcess* ui_active = &ui_menu;

void loop()
{
    toolCH1.setTemps(512, analogRead(TEMP_CH1));
    toolCH2.setTemps(256, analogRead(TEMP_CH2));
    if (digitalRead(BTN_UP) == 0) {
        ui_active = &ui_menu;
    }
    if (digitalRead(BTN_DN) == 0) {
        ui_active = &ui_main;
    }
    ui_active->process();
    delay(100);
}
