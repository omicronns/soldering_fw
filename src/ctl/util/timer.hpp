#pragma once
#include <array>
#include <stdint.h>

template <std::size_t TimersCount>
class Timer
{
    uint32_t last_time = 0;
    std::array<uint32_t, TimersCount> times;
    std::array<uint32_t, TimersCount> periods;

public:
    Timer(std::array<uint32_t, TimersCount> periods) : times{0},
                                                       periods{periods}
    {
    }

    void update(uint32_t time)
    {
        for (std::size_t idx = 0; idx < TimersCount; idx += 1)
        {
            if (times[idx] <= periods[idx])
            {
                times[idx] += time - last_time;
            }
            else
            {
                times[idx] = 0;
            }
            last_time = time;
        }
    }

    bool trig(std::size_t idx)
    {
        return times[idx] > periods[idx];
    }
};
