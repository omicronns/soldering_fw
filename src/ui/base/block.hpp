#pragma once
#include <array>
#include <ui/base/widget.hpp>


template<std::size_t WidgetsCount>
class UiBlock {
    std::array<UiWidget*, WidgetsCount> schedule;

public:
    UiBlock(std::array<UiWidget*, WidgetsCount> schedule) :
        schedule{schedule}
    {}

    virtual void update() = 0;

    void drawall() {
        update();

        for (auto w : schedule) {
            w->draw();
        }
    }
};
