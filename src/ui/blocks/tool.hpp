#pragma once
#include <ui/base/block.hpp>
#include <ui/base/util.hpp>
#include <ui/components/rect.hpp>
#include <ui/components/textbox.hpp>

class UiTool : public UiBlock<2>
{
    UiRect background;
    UiTextBox text;

public:
    UiTool(Adafruit_GFX *gfx, int x, int y) : UiBlock<2>{{&background, &text}},
                                              background{gfx, x, y, 40, 16, color565(255, 255, 255)},
                                              text{gfx, x, y, 2, color565(255, 0, 0)}
    {
    }

    void setText(const char *t)
    {
        text.setText(t);
        changed();
    }
};
