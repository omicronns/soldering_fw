#pragma once
#include <array>
#include <ui/base/process.hpp>


template<std::size_t Count>
class UiSchedule : public UiProcess {
    bool changed = true;
    const bool always;
public:
    std::array<UiProcess*, Count> schedule;

    UiSchedule(std::array<UiProcess*, Count> schedule, bool always = false) :
        always{always}, schedule{schedule}
    {}

    void process() {
        if (changed || always) {
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
