#pragma once
#include <array>
#include <stdint.h>
#include <ui/base/widget.hpp>


template<std::size_t WidgetsCount>
class UiBlock {
    std::array<UiWidget*, WidgetsCount> schedule;
    bool redraw = true;

public:
    UiBlock(std::array<UiWidget*, WidgetsCount> schedule) :
        schedule{schedule}
    {}

    void process() {
        if (redraw) {
            redraw = false;

            for (auto w : schedule) {
                w->draw();
            }
        }
    }

    void changed() {
        redraw = true;
    }
};
