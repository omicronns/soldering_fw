#pragma once
#include <ui/base/schedule.hpp>
#include <ui/base/util.hpp>
#include <ui/components/printbox.hpp>

class UiTool : public UiSchedule<2>
{
    UiPrintBox tempSet;
    UiPrintBox tempAct;
    UiNumberPrinter printerSet;
    UiNumberPrinter printerAct;
public:
    UiTool(Adafruit_GFX *gfx, UiVec orig) : 
        UiSchedule<2>{{&tempSet, &tempAct}},
        tempSet{gfx, {orig.x + 2, orig.y + 2}, 2, &printerSet, color565(255, 0, 0), color565(255, 255, 255)},
        tempAct{gfx, {orig.x + 2, orig.y + 20}, 2, &printerAct, color565(255, 0, 0), color565(255, 255, 255)}
    {
    }

    void setTemps(int set, int act)
    {
        printerSet.setValue(set);
        printerAct.setValue(act);
        update();
    }
};
