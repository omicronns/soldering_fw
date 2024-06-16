#pragma once
#include <ui/base/block.hpp>
#include <ui/base/timer.hpp>
#include <ui/base/util.hpp>
#include <ui/components/rect.hpp>
#include <ui/components/textbox.hpp>

class UiTool : public UiBlock<2> {
    struct ToolTimers {
        enum {
            Text,
            Count
        };
    };
    UiTimer<ToolTimers::Count> timer;
    UiRect background;
    UiTextBox text;

    std::array<const char*, 3> texts = {
    "qwe", "asd", "zxc"
    };
    int idx_texts = 0;
public:
    UiTool(Adafruit_GFX* gfx, int x, int y) :
        UiBlock<2>{{&background, &text}},
        timer{{5}},
        background{gfx, x, y, 32, 16, color565(255, 255, 255)},
        text{gfx, x, y, color565(255, 0, 0)}
    {}

    void update() {
        timer.update();

        if (timer.trig(ToolTimers::Text)) {
            text.setText(texts[idx_texts]);
            idx_texts = (idx_texts + 1) % texts.size();
        }
    }
};
