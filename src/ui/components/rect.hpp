#pragma once
#include <ui/base/widget.hpp>


class UiRect : public UiWidget {
    int w, h;
    uint16_t color;
    bool full;

    void draw() const {
        if (full) {
            gfx->fillRect(x, y, w, h, color);
        }
        else {
            gfx->drawRect(x, y, w, h, color);
        }
    }
public:
    UiRect(Adafruit_GFX* gfx, int pos_x, int pos_y, int w, int h, uint16_t color = 0, bool full = true) :
        UiWidget(gfx, pos_x, pos_y), w{w}, h{h}, color{color}, full{full}
    {}

    void setColor(uint16_t color) {
        this->color = color;
    }

    void resize(int w, int h) {
        this->w = w;
        this->h = h;
    }
};
