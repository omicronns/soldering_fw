#pragma once
#include <util/timer.hpp>


template<std::size_t Count>
class InputMgr {
public:
    enum class Type {
        Single,
        Double
    };

    enum class Event {
        Idle,
        Single,
        Double,
        Long
    };

private:
    enum class State {
        Idle,
        Pressed0,
        Unpressed1,
        Pressed1,
        Cooldown
    };

    std::array<Type, Count> cfg;
    std::array<State, Count> state;
    std::array<Event, Count> events;
    Timer<Count> timer;

public:
    InputMgr(std::array<Type, Count> cfg, uint32_t period) :
        cfg{cfg}, state{State::Idle}, events{Event::Idle}, timer{{period}}
    {
    }

    void process(uint32_t time, std::array<int, Count> values) {
        timer.update(time);

        for(int idx = 0; idx < Count; idx += 1) {
            switch (state[idx]) {
                case State::Idle:
                    if (values[idx] == 0) {
                        state[idx] = State::Pressed0;
                        timer.trig(idx);
                    }
                    break;
                case State::Pressed0:
                    if (timer.trig(idx)) {
                        if (values[idx] == 0) {
                            if (cfg[idx] == Type::Double) {
                                state[idx] = State::Pressed1;
                            }
                        }
                        else {
                            if (cfg[idx] == Type::Single) {
                                state[idx] = State::Cooldown;
                                events[idx] = Event::Single;
                            }
                            if (cfg[idx] == Type::Double) {
                                state[idx] = State::Unpressed1;
                            }
                        }
                    }
                    break;
                case State::Unpressed1:
                    if (timer.trig(idx)) {
                        if (values[idx] == 0) {
                            state[idx] = State::Cooldown;
                            events[idx] = Event::Double;
                        }
                        else {
                            state[idx] = State::Cooldown;
                            events[idx] = Event::Single;
                        }
                    }
                    break;
                case State::Pressed1:
                    if (timer.trig(idx)) {
                        if (values[idx] == 0) {
                            state[idx] = State::Cooldown;
                            events[idx] = Event::Long;
                        }
                        else {
                            state[idx] = State::Cooldown;
                            events[idx] = Event::Single;
                        }
                    }
                    break;
                case State::Cooldown:
                    if (values[idx] != 0) {
                        state[idx] = State::Idle;
                    }
                    break;
            }
        }
    }

    Event poll(std::size_t idx) {
        Event evt = events[idx];
        events[idx] = Event::Idle;
        return evt;
    }
};
