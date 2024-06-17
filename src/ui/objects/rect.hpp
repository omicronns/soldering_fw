#pragma once
#include <ui/base/object.hpp>

class UiRect : public UiObject
{
    UiVec size;
    uint16_t color;
    bool fill;

    void update()
    {
        if (fill)
        {
            gfx->fillRect(orig.x, orig.y, size.x, size.y, color);
        }
        else
        {
            gfx->drawRect(orig.x, orig.y, size.x, size.y, color);
        }
    }

public:
    UiRect(Adafruit_GFX *gfx, UiBox box, uint16_t color = 0, bool fill = true) :
        UiObject(gfx, box.orig), size{box.size}, color{color}, fill{fill}
    {
    }

    void setColor(uint16_t color)
    {
        this->color = color;
    }

    void resize(UiVec size)
    {
        this->size = size;
    }
};
