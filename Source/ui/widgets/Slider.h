#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

class Slider : public juce::Slider
{
public:
    Slider(uint32_t _id, double _min, double _max, double _interval, double defval = 0, bool _bipolar= false, bool _vertical = false)
        : juce::Slider("Slider"), id(_id), min(_min), max(_max), interval(_interval), defval(defval), bipolar(_bipolar), vertical(_vertical)
    {
        setSliderStyle(vertical ? juce::Slider::SliderStyle::LinearBarVertical
                                : juce::Slider::SliderStyle::LinearBar);
        setRange(min, max, interval);
    };

    void mouseDown(const juce::MouseEvent &e) override
    {
        if (e.mods.isRightButtonDown())
        {
            setValue(defval);
        }
        else
        {
            juce::Slider::mouseDown(e);
        }
    }

    uint32_t getID() { return id; }

private:
    uint32_t id;
    bool vertical, bipolar;
    double min, max, defval, interval;
};