#pragma once


class UiProcess {
    bool always;
    bool changed;
public:
    UiProcess(bool always = false, bool changed = true) :
        always{always}, changed{changed}
    {
    }

    virtual void update() = 0;

    void process() {
        if (changed || always) {
            changed = false;
            update();
        }
    }

    void mark() {
        changed = true;
    }
};
