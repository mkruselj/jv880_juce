/*
  ==============================================================================

    EditCommonTab.h
    Created: 20 Aug 2024 2:33:58pm
    Author:  Giulio Zausa

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "../PluginProcessor.h"
#include "../dataStructures.h"

#include "widgets/Button.h"
#include "widgets/Menu.h"
#include "widgets/Slider.h"
#include "widgets/TextEdit.h"

constexpr int MAX_PATCH_NAME_CHARS = 12;

class EditCommonTab : public juce::Component,
                      public juce::Slider::Listener,
                      public juce::Button::Listener,
                      public juce::ComboBox::Listener,
                      public juce::TextEditor::Listener
{
public:
  EditCommonTab(VirtualJVProcessor &);
  ~EditCommonTab() override;


  void resized() override;
  void sliderValueChanged(juce::Slider*) override;
  void buttonClicked(juce::Button *) override;
  void buttonStateChanged(juce::Button*) override {}
  void comboBoxChanged(juce::ComboBox *) override;
  void textEditorTextChanged(juce::TextEditor &) override;

  void updateValues();

  void sendSysexPatchNameChange();
  void sendSysexPatchCommonParamChange(const uint8_t address, const uint8_t value);

private:
  enum EditSystemWidgets
  {
    ScaleTuneSwitch     = 10U,
    PatchScaleC         = 11U,
    PatchScaleCSharp    = 12U,
    PatchScaleD         = 13U,
    PatchScaleDSharp    = 14U,
    PatchScaleE         = 15U,
    PatchScaleF         = 16U,
    PatchScaleFSharp    = 17U,
    PatchScaleG         = 18U,
    PatchScaleGSharp    = 19U,
    PatchScaleA         = 20U,
    PatchScaleASharp    = 21U,
    PatchScaleB         = 22U,
  };

  enum EditCommonWidgets
  {
    PatchName           = 100U,
    VelocitySwitch      = 101U,

    ReverbType          = 110U,
    ReverbLevel         = 111U,
    ReverbTime          = 112U,
    DelayFeedback       = 113U,

    ChorusType          = 120U,
    ChorusLevel         = 121U,
    ChorusDepth         = 122U,
    ChorusRate          = 123U,
    ChorusFeedback      = 124U,
    ChorusOutput        = 125U,

    AnalogFeel          = 130U,
    Level               = 131U,
    Pan                 = 132U,

    BendRangeDown       = 140U,
    BendRangeUp         = 141U,
    KeyAssign           = 142U,
    SoloLegato          = 143U,
    Portamento          = 144U,
    PortamentoMode      = 145U,
    PortamentoType      = 146U,
    PortamentoTime      = 147U,
  };

  VirtualJVProcessor &processor;

  juce::Label levelLabel{ "", "Level" };
  juce::Label panLabel{ "", "Pan" };
  juce::Label analogFeelLabel{ "", "Analog Feel" };
  Slider levelSlider{ Level, 0, 127, 1, 96 };
  Slider panSlider{ Pan, -64, 63, 1, true };
  Slider analogFeelSlider{ AnalogFeel, 0, 127, 1 };

  juce::Label bendRangeLabel{ "", "Bend Range" };
  juce::Label keyAssignLabel{ "", "Key Assign" };
  juce::Label portamentoModeLabel{ "", "Mode" };
  juce::Label portamentoTypeLabel{ "", "Type" };
  juce::Label portamentoTimeLabel{ "", "Time" };
  Slider bendRangeDownSlider{ BendRangeDown, -48, 0, 1, -2 };
  Slider bendRangeUpSlider{ BendRangeUp, 0, 12, 1, 2 };
  Menu keyAssignComboBox{ KeyAssign, 0 };
  Button soloLegatoToggle{ SoloLegato, "Legato" };
  Button portamentoToggle{ Portamento, "Portamento" };
  Menu portamentoModeComboBox{ PortamentoMode, 1 };
  Menu portamentoTypeComboBox{ PortamentoType };
  Slider portamentoTimeSlider{ PortamentoTime, 0, 127, 1 };


  juce::Label patchNameLabel{ "", "Patch Name" };
  TextEdit patchNameEditor{ PatchName };
  Button velocitySwitchToggle{ VelocitySwitch, "Velocity Switch" };

  juce::Label reverbTypeLabel{ "", "Reverb" };
  juce::Label reverbLevelLabel{ "", "Level" };
  juce::Label reverbTimeLabel{ "", "Time" };
  juce::Label delayFeedbackLabel{ "", "Feedback" };
  Menu reverbTypeComboBox{ ReverbType, 4 };
  Slider reverbLevelSlider{ ReverbLevel, 0, 127, 1, 64 };
  Slider reverbTimeSlider{ ReverbTime, 0, 127, 1, 64 };
  Slider delayFeedbackSlider{ DelayFeedback, 0, 127, 1, 64 };;

  juce::Label chorusTypeLabel{ "", "Chorus" };
  juce::Label chorusLevelLabel{ "", "Level" };
  juce::Label chorusDepthLabel{ "", "Depth" };
  juce::Label chorusRateLabel{ "", "Rate" };
  juce::Label chorusFeedbackLabel{ "", "Feedback" };
  juce::Label chorusOutputLabel{ "", "Output" };
  Menu chorusTypeComboBox{ ChorusType, 1 };
  Slider chorusLevelSlider{ ChorusLevel, 0, 127, 1, 64 };
  Slider chorusDepthSlider{ ChorusDepth, 0, 127, 1, 64 };
  Slider chorusRateSlider{ ChorusRate, 0, 127, 1, 32 };
  Slider chorusFeedbackSlider{ ChorusFeedback, 0, 127, 1 };
  Menu chorusOutputComboBox{ ChorusOutput };

  Button scaleTuneSwitch{ ScaleTuneSwitch, "Scale Tune" };
  Slider patchScaleCSlider{ PatchScaleC, -64, 63, 1, 0, true, true };
  Slider patchScaleCSharpSlider{ PatchScaleCSharp, -64, 63, 1, 0, true, true };
  Slider patchScaleDSlider{ PatchScaleD, -64, 63, 1, 0, true, true };
  Slider patchScaleDSharpSlider{ PatchScaleDSharp, -64, 63, 1, 0, true, true };
  Slider patchScaleESlider{ PatchScaleE, -64, 63, 1, 0, true, true };
  Slider patchScaleFSlider{ PatchScaleF, -64, 63, 1, 0, true, true };
  Slider patchScaleFSharpSlider{ PatchScaleFSharp, -64, 63, 1, 0, true, true };
  Slider patchScaleGSlider{ PatchScaleG, -64, 63, 1, 0, true, true };
  Slider patchScaleGSharpSlider{ PatchScaleGSharp, -64, 63, 1, 0, true, true };
  Slider patchScaleASlider{ PatchScaleA, -64, 63, 1, 0, true, true };
  Slider patchScaleASharpSlider{ PatchScaleASharp, -64, 63, 1, 0, true, true };
  Slider patchScaleBSlider{ PatchScaleB, -64, 63, 1, 0, true, true };
  juce::Label patchScaleCLabel{ "", "C" };
  juce::Label patchScaleCSharpLabel{ "", "C#" };
  juce::Label patchScaleDLabel{ "", "D" };
  juce::Label patchScaleDSharpLabel{ "", "D#" };
  juce::Label patchScaleELabel{ "", "E" };
  juce::Label patchScaleFLabel{ "", "F" };
  juce::Label patchScaleFSharpLabel{ "", "F#" };
  juce::Label patchScaleGLabel{ "", "G" };
  juce::Label patchScaleGSharpLabel{ "", "G#" };
  juce::Label patchScaleALabel{ "", "A" };
  juce::Label patchScaleASharpLabel{ "", "A#" };
  juce::Label patchScaleBLabel{ "", "B" };

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(EditCommonTab)
};
