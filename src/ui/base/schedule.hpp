#pragma once
#include <array>
#include <ui/base/process.hpp>


template<std::size_t Count>
class UiSchedule : public UiProcess {
    std::array<UiProcess*, Count> schedule;
public:
    UiSchedule(std::array<UiProcess*, Count> schedule) :
        UiProcess{true}, schedule{schedule}
    {}

    void update() {
        for (auto ui : schedule) {
            ui->process();
        }
    }
};
