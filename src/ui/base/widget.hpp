#pragma once
#include <ui/base/process.hpp>
#include <Adafruit_GFX.h>


struct UiVec {
    int x, y;
};

struct UiBox {
    UiVec orig;
    UiVec size;
};

class UiWidget : public UiProcessBase
{
protected:
    Adafruit_GFX *gfx;
    UiVec orig;

public:
    UiWidget(Adafruit_GFX *gfx, UiVec orig) : gfx{gfx}, orig{orig}
    {
    }
};
