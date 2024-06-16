#pragma once
#include <ui/base/object.hpp>

struct UiPrinter
{
    virtual void operator()(Adafruit_GFX *) = 0;
};

struct UiNumberPrinter : public UiPrinter
{
    int value;

    virtual void operator()(Adafruit_GFX *gfx)
    {
        gfx->print(value);
    }

    void setValue(int value)
    {
        this->value = value;
    }
};

class UiPrintBox : public UiObject
{
    UiPrinter *printer;
    uint8_t size;
    uint16_t colorfg;
    uint16_t colorbg;

    void process()
    {
        if (printer)
        {
            gfx->setTextSize(size);
            gfx->setTextColor(colorfg, colorbg);
            gfx->setCursor(orig.x, orig.y);
            (*printer)(gfx);
        }
    }

public:
    UiPrintBox(Adafruit_GFX *gfx, UiVec orig, uint8_t size, UiPrinter *printer, uint16_t colorfg = 0, uint16_t colorbg = 0) :
        UiObject(gfx, orig), printer{printer}, size{size}, colorfg{colorfg}
    {
    }

    void setColors(uint16_t colorfg, uint16_t colorbg)
    {
        this->colorfg = colorfg;
        this->colorbg = colorbg;
    }
};
