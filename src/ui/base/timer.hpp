#pragma once
#include <array>


template<std::size_t TimersCount>
class UiTimer {
    std::array<std::size_t, TimersCount> ticks;
    std::array<std::size_t, TimersCount> periods;
public:
    UiTimer(std::array<std::size_t, TimersCount> periods) :
        ticks{0},
        periods{periods}
    {}

    void update() {
        for (std::size_t idx = 0; idx < TimersCount; idx += 1) {
            if (ticks[idx] < periods[idx]) {
                ticks[idx] += 1;
            }
            else {
                ticks[idx] = 0;
            }
        }
    }

    bool trig(std::size_t idx) {
        return ticks[idx] == periods[idx];
    }
};
