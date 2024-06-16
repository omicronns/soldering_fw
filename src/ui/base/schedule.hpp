#pragma once
#include <array>
#include <ui/base/process.hpp>


template<std::size_t Count>
class UiSchedule : public UiProcessBase {
    bool changed;
public:
    std::array<UiProcessBase*, Count> schedule;

    UiSchedule(std::array<UiProcessBase*, Count> schedule) :
        schedule{schedule}
    {}

    void process() {
        if (changed) {
            changed = false;

            for (auto ui : schedule) {
                ui->process();
            }
        }
    }

    void update() {
        changed = true;
    }
};
