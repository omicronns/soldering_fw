#pragma once
#include <ui/base/widget.hpp>


class UiTextBox : public UiWidget {
    const char* text;
    uint16_t color;

    void draw() const {
        if (text) {
            gfx->setTextColor(color);
            gfx->setCursor(x, y);
            gfx->print(text);
        }
    }
public:
    UiTextBox(Adafruit_GFX* gfx, int x, int y, uint16_t color = 0) :
        UiWidget(gfx, x, y), text{nullptr}, color{color}
    {}

    void setText(const char* text) {
        this->text = text;
    }

    void setColor(uint16_t color) {
        this->color = color;
    }
};
