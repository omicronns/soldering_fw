#pragma once
#include <Adafruit_GFX.h>


class UiWidget {
protected:
    Adafruit_GFX* gfx;
    int x, y;
public:
    UiWidget(Adafruit_GFX* gfx, int x, int y) :
        gfx{gfx}, x{x}, y{y}
    {}

    virtual void draw() const = 0;

    virtual void move(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
