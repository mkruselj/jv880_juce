/*
  ==============================================================================

    EditCommonTab.cpp
    Created: 20 Aug 2024 2:33:58pm
    Author:  Giulio Zausa

  ==============================================================================
*/

#include <JuceHeader.h>
#include "EditCommonTab.h"

//==============================================================================
EditCommonTab::EditCommonTab(VirtualJVProcessor& p) : processor (p)
{
    addAndMakeVisible(levelSlider);
    levelSlider.addListener(this);

    addAndMakeVisible(levelLabel);
    levelLabel.attachToComponent(&levelSlider, true);

    addAndMakeVisible(panSlider);
    panSlider.addListener(this);

    addAndMakeVisible(panLabel);
    panLabel.attachToComponent(&panSlider, true);

    addAndMakeVisible(analogFeelSlider);
    analogFeelSlider.addListener(this);

    addAndMakeVisible(analogFeelLabel);
    analogFeelLabel.attachToComponent(&analogFeelSlider, true);

    addAndMakeVisible(bendRangeDownSlider);
    bendRangeDownSlider.addListener(this);

    addAndMakeVisible(bendRangeLabel);
    bendRangeLabel.attachToComponent(&bendRangeDownSlider, true);

    addAndMakeVisible(bendRangeUpSlider);
    bendRangeUpSlider.addListener(this);

    addAndMakeVisible(keyAssignLabel);
    keyAssignLabel.attachToComponent(&keyAssignComboBox, true);

    addAndMakeVisible(keyAssignComboBox);
    keyAssignComboBox.addListener(this);
    keyAssignComboBox.addItem("Poly", 1);
    keyAssignComboBox.addItem("Solo", 2);

    addAndMakeVisible(soloLegatoToggle);
    soloLegatoToggle.addListener(this);

    addAndMakeVisible(portamentoToggle);
    portamentoToggle.addListener(this);

    addAndMakeVisible(portamentoModeLabel);
    portamentoModeLabel.attachToComponent(&portamentoModeComboBox, true);

    addAndMakeVisible(portamentoModeComboBox);
    portamentoModeComboBox.addListener(this);
    portamentoModeComboBox.addItem("Legato", 1);
    portamentoModeComboBox.addItem("Normal", 2);

    addAndMakeVisible(portamentoTypeLabel);
    portamentoTypeLabel.attachToComponent(&portamentoTypeComboBox, true);

    addAndMakeVisible(portamentoTypeComboBox);
    portamentoTypeComboBox.addListener(this);
    portamentoTypeComboBox.addItem("Time", 1);
    portamentoTypeComboBox.addItem("Rate", 2);

    addAndMakeVisible(portamentoTimeSlider);
    portamentoTimeSlider.addListener(this);

    addAndMakeVisible(portamentoTimeLabel);
    portamentoTimeLabel.attachToComponent(&portamentoTimeSlider, true);


    addAndMakeVisible(patchNameEditor);
    patchNameEditor.addListener(this);
    patchNameEditor.setInputRestrictions(MAX_PATCH_NAME_CHARS,
        " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+-*/#!,.");
    addAndMakeVisible(patchNameLabel);
    patchNameLabel.attachToComponent(&patchNameEditor, true);

    addAndMakeVisible(velocitySwitchToggle);
    velocitySwitchToggle.addListener(this);

    addAndMakeVisible(reverbTypeLabel);
    reverbTypeLabel.attachToComponent(&reverbTypeComboBox, true);

    addAndMakeVisible(reverbTypeComboBox);
    reverbTypeComboBox.addListener(this);
    reverbTypeComboBox.addItem("Room 1", 1);
    reverbTypeComboBox.addItem("Room 2", 2);
    reverbTypeComboBox.addItem("Stage 1", 3);
    reverbTypeComboBox.addItem("Stage 2", 4);
    reverbTypeComboBox.addItem("Hall 1", 5);
    reverbTypeComboBox.addItem("Hall 2", 6);
    reverbTypeComboBox.addItem("Delay", 7);
    reverbTypeComboBox.addItem("Pan Delay", 8);

    addAndMakeVisible(reverbLevelSlider);
    reverbLevelSlider.addListener(this);

    addAndMakeVisible(reverbLevelLabel);
    reverbLevelLabel.attachToComponent(&reverbLevelSlider, true);

    addAndMakeVisible(reverbTimeSlider);
    reverbTimeSlider.addListener(this);

    addAndMakeVisible(reverbTimeLabel);
    reverbTimeLabel.attachToComponent(&reverbTimeSlider, true);

    addAndMakeVisible(delayFeedbackSlider);
    delayFeedbackSlider.addListener(this);

    addAndMakeVisible(delayFeedbackLabel);
    delayFeedbackLabel.attachToComponent(&delayFeedbackSlider, true);

    addAndMakeVisible(chorusTypeLabel);
    chorusTypeLabel.attachToComponent(&chorusTypeComboBox, true);

    addAndMakeVisible(chorusTypeComboBox);
    chorusTypeComboBox.addListener(this);
    chorusTypeComboBox.addItem("Type 1", 1);
    chorusTypeComboBox.addItem("Type 2", 2);
    chorusTypeComboBox.addItem("Type 3", 3);

    addAndMakeVisible(chorusLevelSlider);
    chorusLevelSlider.addListener(this);

    addAndMakeVisible(chorusLevelLabel);
    chorusLevelLabel.attachToComponent(&chorusLevelSlider, true);

    addAndMakeVisible(chorusDepthSlider);
    chorusDepthSlider.addListener(this);

    addAndMakeVisible(chorusDepthLabel);
    chorusDepthLabel.attachToComponent(&chorusDepthSlider, true);

    addAndMakeVisible(chorusRateSlider);
    chorusRateSlider.addListener(this);

    addAndMakeVisible(chorusRateLabel);
    chorusRateLabel.attachToComponent(&chorusRateSlider, true);

    addAndMakeVisible(chorusFeedbackSlider);
    chorusFeedbackSlider.addListener(this);

    addAndMakeVisible(chorusFeedbackLabel);
    chorusFeedbackLabel.attachToComponent(&chorusFeedbackSlider, true);

    addAndMakeVisible(chorusOutputLabel);
    chorusOutputLabel.attachToComponent(&chorusOutputComboBox, true);

    addAndMakeVisible(chorusOutputComboBox);
    chorusOutputComboBox.addListener(this);
    chorusOutputComboBox.addItem("Mix", 1);
    chorusOutputComboBox.addItem("Reverb", 2);


    addAndMakeVisible(scaleTuneSwitch);
    scaleTuneSwitch.addListener(this);
    addAndMakeVisible(patchScaleCSlider);
    patchScaleCSlider.addListener(this);
    addAndMakeVisible(patchScaleCSharpSlider);
    patchScaleCSharpSlider.addListener(this);
    addAndMakeVisible(patchScaleDSlider);
    patchScaleDSlider.addListener(this);
    addAndMakeVisible(patchScaleDSharpSlider);
    patchScaleDSharpSlider.addListener(this);
    addAndMakeVisible(patchScaleESlider);
    patchScaleESlider.addListener(this);
    addAndMakeVisible(patchScaleFSlider);
    patchScaleFSlider.addListener(this);
    addAndMakeVisible(patchScaleFSharpSlider);
    patchScaleFSharpSlider.addListener(this);
    addAndMakeVisible(patchScaleGSlider);
    patchScaleGSlider.addListener(this);
    addAndMakeVisible(patchScaleGSharpSlider);
    patchScaleGSharpSlider.addListener(this);
    addAndMakeVisible(patchScaleASlider);
    patchScaleASlider.addListener(this);
    addAndMakeVisible(patchScaleASharpSlider);
    patchScaleASharpSlider.addListener(this);
    addAndMakeVisible(patchScaleBSlider);
    patchScaleBSlider.addListener(this);

    addAndMakeVisible(patchScaleCLabel);
    patchScaleCLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleCSharpLabel);
    patchScaleCSharpLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleDLabel);
    patchScaleDLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleDSharpLabel);
    patchScaleDSharpLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleELabel);
    patchScaleELabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleFLabel);
    patchScaleFLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleFSharpLabel);
    patchScaleFSharpLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleGLabel);
    patchScaleGLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleGSharpLabel);
    patchScaleGSharpLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleALabel);
    patchScaleALabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleASharpLabel);
    patchScaleASharpLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(patchScaleBLabel);
    patchScaleBLabel.setJustificationType(juce::Justification::centred);
}

EditCommonTab::~EditCommonTab()
{
}

void EditCommonTab::updateValues()
{
    auto system = &processor.status;
    auto patch = (Patch*)processor.status.patch;

    levelSlider             .setValue(patch->level, juce::dontSendNotification);
    panSlider               .setValue(patch->pan - 64, juce::dontSendNotification);
    analogFeelSlider        .setValue(patch->analogFeel, juce::dontSendNotification);
    bendRangeDownSlider     .setValue(((patch->bendRange) & 0x3f) - 64, juce::dontSendNotification);
    bendRangeUpSlider       .setValue(patch->flags & 0xf, juce::dontSendNotification);
    keyAssignComboBox       .setSelectedItemIndex((patch->flags & 0x80) != 0, juce::dontSendNotification);
    soloLegatoToggle        .setToggleState((patch->flags & 0x20) != 0, juce::dontSendNotification);
    portamentoToggle        .setToggleState((patch->flags & 0x40) != 0, juce::dontSendNotification);
    portamentoModeComboBox  .setSelectedItemIndex((patch->flags & 0x10) != 0, juce::dontSendNotification);
    portamentoTypeComboBox  .setSelectedItemIndex((patch->portamentoTime & 0x80) != 0, juce::dontSendNotification);
    portamentoTimeSlider    .setValue(patch->portamentoTime & 0x7f, juce::dontSendNotification);
    patchNameEditor         .setText(juce::String(patch->name, 0xc), juce::dontSendNotification);
    velocitySwitchToggle    .setToggleState((patch->recChorConfig & 0x80) != 0, juce::dontSendNotification);
    reverbTypeComboBox      .setSelectedItemIndex(patch->recChorConfig & 0x7, juce::dontSendNotification);
    reverbLevelSlider       .setValue(patch->reverbLevel, juce::dontSendNotification);
    reverbTimeSlider        .setValue(patch->reverbTime, juce::dontSendNotification);
    delayFeedbackSlider     .setValue(patch->reverbFeedback, juce::dontSendNotification);
    chorusTypeComboBox      .setSelectedItemIndex((patch->recChorConfig >> 4) & 0x3, juce::dontSendNotification);
    chorusLevelSlider       .setValue(patch->chorusLevel & 0x7f, juce::dontSendNotification);
    chorusDepthSlider       .setValue(patch->chorusDepth, juce::dontSendNotification);
    chorusRateSlider        .setValue(patch->chorusRate, juce::dontSendNotification);
    chorusFeedbackSlider    .setValue(patch->chorusFeedback, juce::dontSendNotification);
    chorusOutputComboBox    .setSelectedItemIndex((patch->chorusLevel & 0x80) != 0, juce::dontSendNotification);

    scaleTuneSwitch         .setToggleState((system->scaleTuneEnabled) != 0, juce::dontSendNotification);
    patchScaleCSlider       .setValue(system->scale[0] - 64, juce::dontSendNotification);
    patchScaleCSharpSlider  .setValue(system->scale[1] - 64, juce::dontSendNotification);
    patchScaleDSlider       .setValue(system->scale[2] - 64, juce::dontSendNotification);
    patchScaleDSharpSlider  .setValue(system->scale[3] - 64, juce::dontSendNotification);
    patchScaleESlider       .setValue(system->scale[4] - 64, juce::dontSendNotification);
    patchScaleFSlider       .setValue(system->scale[5] - 64, juce::dontSendNotification);
    patchScaleFSharpSlider  .setValue(system->scale[6] - 64, juce::dontSendNotification);
    patchScaleGSlider       .setValue(system->scale[7] - 64, juce::dontSendNotification);
    patchScaleGSharpSlider  .setValue(system->scale[8] - 64, juce::dontSendNotification);
    patchScaleASlider       .setValue(system->scale[9] - 64, juce::dontSendNotification);
    patchScaleASharpSlider  .setValue(system->scale[10] - 64, juce::dontSendNotification);
    patchScaleBSlider       .setValue(system->scale[11] - 64, juce::dontSendNotification);
}

void EditCommonTab::resized()
{
    const auto top = 30;
    const auto sliderLeft1 = 100;
    const auto width = getWidth() / 2 - sliderLeft1 - 10;
    const auto halfWidth = width / 2;
    const auto sliderLeft2 = getWidth() / 2 + sliderLeft1 + 0;
    const auto height = 24;
    const auto vertWidth = 28;
    const auto vertHeight = 96;
    const auto labelVOffset = vertHeight + 4;
    const auto vMargin = 24;

    levelSlider            .setBounds(sliderLeft1, top + height * 0 + vMargin * 0, width, height);
    panSlider              .setBounds(sliderLeft1, top + height * 1 + vMargin * 0, width, height);

    analogFeelSlider       .setBounds(sliderLeft1, top + height * 2 + vMargin * 1, width, height);

    bendRangeDownSlider    .setBounds(sliderLeft1, top + height * 3 + vMargin * 2, halfWidth, height);
    bendRangeUpSlider      .setBounds(sliderLeft1 + halfWidth, top + height * 3 + vMargin * 2, halfWidth, height);

    keyAssignComboBox      .setBounds(sliderLeft1, top + height * 4 + vMargin * 3, halfWidth, height);
    soloLegatoToggle       .setBounds(sliderLeft1 + halfWidth, top + height * 4 + vMargin * 3, halfWidth, height);

    portamentoToggle       .setBounds(sliderLeft1, top + height * 5 + vMargin * 4, width, height);
    portamentoModeComboBox .setBounds(sliderLeft1, top + height * 6 + vMargin * 4, width, height);
    portamentoTypeComboBox .setBounds(sliderLeft1, top + height * 7 + vMargin * 4, width, height);
    portamentoTimeSlider   .setBounds(sliderLeft1, top + height * 8 + vMargin * 4, width, height);


    patchNameEditor        .setBounds(sliderLeft2, top + height * 0 + vMargin * 0, halfWidth, height);
    velocitySwitchToggle   .setBounds(sliderLeft2 + halfWidth, top + height * 0 + vMargin * 0, halfWidth, height);

    reverbTypeComboBox     .setBounds(sliderLeft2, top + height * 1 + vMargin * 1, width, height);
    reverbLevelSlider      .setBounds(sliderLeft2, top + height * 2 + vMargin * 1, width, height);
    reverbTimeSlider       .setBounds(sliderLeft2, top + height * 3 + vMargin * 1, width, height);
    delayFeedbackSlider    .setBounds(sliderLeft2, top + height * 4 + vMargin * 1, width, height);

    chorusTypeComboBox     .setBounds(sliderLeft2, top + height * 5 + vMargin * 2, width, height);
    chorusLevelSlider      .setBounds(sliderLeft2, top + height * 6 + vMargin * 2, width, height);
    chorusDepthSlider      .setBounds(sliderLeft2, top + height * 7 + vMargin * 2, width, height);
    chorusRateSlider       .setBounds(sliderLeft2, top + height * 8 + vMargin * 2, width, height);
    chorusFeedbackSlider   .setBounds(sliderLeft2, top + height * 9 + vMargin * 2, width, height);
    chorusOutputComboBox   .setBounds(sliderLeft2, top + height * 10 + vMargin * 2, width, height);

    scaleTuneSwitch        .setBounds(sliderLeft1, top + height * 9 + vMargin * 6, halfWidth, height);
    patchScaleCSlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 0), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleCSharpSlider .setBounds(sliderLeft1 - 37 + (vertWidth * 1), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleDSlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 2), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleDSharpSlider .setBounds(sliderLeft1 - 37 + (vertWidth * 3), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleESlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 4), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleFSlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 5), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleFSharpSlider .setBounds(sliderLeft1 - 37 + (vertWidth * 6), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleGSlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 7), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleGSharpSlider .setBounds(sliderLeft1 - 37 + (vertWidth * 8), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleASlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 9), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleASharpSlider .setBounds(sliderLeft1 - 37 + (vertWidth * 10), top + height * 10 + vMargin * 6, vertWidth, vertHeight);
    patchScaleBSlider      .setBounds(sliderLeft1 - 37 + (vertWidth * 11), top + height * 10 + vMargin * 6, vertWidth, vertHeight);

    patchScaleCLabel       .setBounds(patchScaleCSlider.getX(), patchScaleCSlider.getY() + labelVOffset, patchScaleCSlider.getWidth(), 14);
    patchScaleCSharpLabel  .setBounds(patchScaleCSharpSlider.getX(), patchScaleCSharpSlider.getY() + labelVOffset, patchScaleCSharpSlider.getWidth(), 14);
    patchScaleDLabel       .setBounds(patchScaleDSlider.getX(), patchScaleDSlider.getY() + labelVOffset, patchScaleDSlider.getWidth(), 14);
    patchScaleDSharpLabel  .setBounds(patchScaleDSharpSlider.getX(), patchScaleDSharpSlider.getY() + labelVOffset, patchScaleDSharpSlider.getWidth(), 14);
    patchScaleELabel       .setBounds(patchScaleESlider.getX(), patchScaleESlider.getY() + labelVOffset, patchScaleESlider.getWidth(), 14);
    patchScaleFLabel       .setBounds(patchScaleFSlider.getX(), patchScaleFSlider.getY() + labelVOffset, patchScaleFSlider.getWidth(), 14);
    patchScaleFSharpLabel  .setBounds(patchScaleFSharpSlider.getX(), patchScaleFSharpSlider.getY() + labelVOffset, patchScaleFSharpSlider.getWidth(), 14);
    patchScaleGLabel       .setBounds(patchScaleGSlider.getX(), patchScaleGSlider.getY() + labelVOffset, patchScaleGSlider.getWidth(), 14);
    patchScaleGSharpLabel  .setBounds(patchScaleGSharpSlider.getX(), patchScaleGSharpSlider.getY() + labelVOffset, patchScaleGSharpSlider.getWidth(), 14);
    patchScaleALabel       .setBounds(patchScaleASlider.getX(), patchScaleASlider.getY() + labelVOffset, patchScaleASlider.getWidth(), 14);
    patchScaleASharpLabel  .setBounds(patchScaleASharpSlider.getX(), patchScaleASharpSlider.getY() + labelVOffset, patchScaleASharpSlider.getWidth(), 14);
    patchScaleBLabel       .setBounds(patchScaleBSlider.getX(), patchScaleBSlider.getY() + labelVOffset, patchScaleBSlider.getWidth(), 14);
}

void EditCommonTab::sliderValueChanged(juce::Slider* slider)
{
    uint32_t id = 0xFFFFFFF;

    if (auto i = dynamic_cast<Slider*>(slider))
    {
        id = i->getID();
    }

    auto system = &processor.status;
    auto patch = (Patch*)processor.status.patch;
    uint8_t value = 0U;

    switch (id)
    {
    case ReverbLevel:
        value = reverbLevelSlider.getValue();
        sendSysexPatchCommonParamChange(0x0e, value);
        patch->reverbLevel = value;
        break;
    case ReverbTime:
        value = reverbTimeSlider.getValue();
        sendSysexPatchCommonParamChange(0x0f, value);
        patch->reverbTime = value;
        break;
    case DelayFeedback:
        value = delayFeedbackSlider.getValue();
        sendSysexPatchCommonParamChange(0x10, value);
        patch->reverbFeedback = value;
        break;
    case ChorusLevel:
        value = chorusLevelSlider.getValue();
        sendSysexPatchCommonParamChange(0x12, value);
        patch->chorusLevel = uint8_t(value + (chorusOutputComboBox.getSelectedItemIndex() << 7));
        break;
    case ChorusDepth:
        value = chorusDepthSlider.getValue();
        sendSysexPatchCommonParamChange(0x13, value);
        patch->chorusDepth = value;
        break;
    case ChorusRate:
        value = chorusRateSlider.getValue();
        sendSysexPatchCommonParamChange(0x14, value);
        patch->chorusRate = value;
        break;
    case ChorusFeedback:
        value = chorusFeedbackSlider.getValue();
        sendSysexPatchCommonParamChange(0x15, value);
        patch->chorusFeedback = value;
        break;
    case AnalogFeel:
        value = analogFeelSlider.getValue();
        sendSysexPatchCommonParamChange(0x17, value);
        patch->analogFeel = value;
        break;
    case Level:
        value = levelSlider.getValue();
        sendSysexPatchCommonParamChange(0x18, value);
        patch->level = value;
        break;
    case Pan:
        value = panSlider.getValue() + 64;
        sendSysexPatchCommonParamChange(0x19, value);
        patch->pan = value;
        break;
    case BendRangeDown:
        value = bendRangeDownSlider.getValue() + 64;
        sendSysexPatchCommonParamChange(0x1a, value);
        patch->bendRange = value;
        break;
    case BendRangeUp:
        sendSysexPatchCommonParamChange(0x1b, uint8_t(bendRangeUpSlider.getValue()));
        patch->flags = uint8_t(bendRangeUpSlider.getValue()
                               + (portamentoModeComboBox.getSelectedItemIndex() << 4)
                               + (soloLegatoToggle.getToggleState() << 5)
                               + (portamentoToggle.getToggleState() << 6)
                               + (keyAssignComboBox.getSelectedItemIndex() << 7));
        break;
    case PortamentoTime:
        sendSysexPatchCommonParamChange(0x21, uint8_t(portamentoTimeSlider.getValue()));
        patch->portamentoTime = uint8_t(portamentoTimeSlider.getValue()
                                        + (portamentoTypeComboBox.getSelectedItemIndex() << 7));
        break;
    case PatchScaleC:
        value = patchScaleCSlider.getValue() + 64;
        processor.sendSysexParamChange(0x0104, value);
        system->scale[0] = value;
        break;
    case PatchScaleCSharp:
        value = patchScaleCSharpSlider.getValue() + 64;
        processor.sendSysexParamChange(0x0105, value);
        system->scale[1] = value;
        break;
    case PatchScaleD:
        value = patchScaleDSlider.getValue() + 64;
        processor.sendSysexParamChange(0x0106, value);
        system->scale[2] = value;
        break;
    case PatchScaleDSharp:
        value = patchScaleDSharpSlider.getValue() + 64;
        processor.sendSysexParamChange(0x0107, value);
        system->scale[3] = value;
        break;
    case PatchScaleE:
        value = patchScaleESlider.getValue() + 64;
        processor.sendSysexParamChange(0x0108, value);
        system->scale[4] = value;
        break;
    case PatchScaleF:
        value = patchScaleFSlider.getValue() + 64;
        processor.sendSysexParamChange(0x0109, value);
        system->scale[5] = value;
        break;
    case PatchScaleFSharp:
        value = patchScaleFSharpSlider.getValue() + 64;
        processor.sendSysexParamChange(0x010A, value);
        system->scale[6] = value;
        break;
    case PatchScaleG:
        value = patchScaleGSlider.getValue() + 64;
        processor.sendSysexParamChange(0x010B, value);
        system->scale[7] = value;
        break;
    case PatchScaleGSharp:
        value = patchScaleGSharpSlider.getValue() + 64;
        processor.sendSysexParamChange(0x010C, value);
        system->scale[8] = value;
        break;
    case PatchScaleA:
        value = patchScaleASlider.getValue() + 64;
        processor.sendSysexParamChange(0x010D, value);
        system->scale[9] = value;
        break;
    case PatchScaleASharp:
        value = patchScaleASharpSlider.getValue() + 64;
        processor.sendSysexParamChange(0x010E, value);
        system->scale[10] = value;
        break;
    case PatchScaleB:
        value = patchScaleBSlider.getValue() + 64;
        processor.sendSysexParamChange(0x010F, value);
        system->scale[11] = value;
        break;
    default:
        break;
    }
}

void EditCommonTab::buttonClicked(juce::Button* button)
{
    uint32_t id = 0xFFFFFFF;

    if (auto i = dynamic_cast<Button*>(button))
    {
        id = i->getID();
    }

    auto system = &processor.status;
    auto patch = (Patch*)processor.status.patch;

    switch (id)
    {
    case VelocitySwitch:
        sendSysexPatchCommonParamChange(0x0c, uint8_t(velocitySwitchToggle.getToggleStateValue() == 1));
        patch->recChorConfig = uint8_t(reverbTypeComboBox.getSelectedItemIndex()
                                       + (chorusTypeComboBox.getSelectedItemIndex() << 4)
                                       + (velocitySwitchToggle.getToggleState() << 7));
        break;
    case SoloLegato:
        sendSysexPatchCommonParamChange(0x1d, uint8_t(soloLegatoToggle.getToggleStateValue() == 1));
        patch->flags = uint8_t(bendRangeUpSlider.getValue()
                               + (portamentoModeComboBox.getSelectedItemIndex() << 4)
                               + (soloLegatoToggle.getToggleState() << 5)
                               + (portamentoToggle.getToggleState() << 6)
                               + (keyAssignComboBox.getSelectedItemIndex() << 7));
        break;
    case Portamento:
        sendSysexPatchCommonParamChange(0x1e, uint8_t(portamentoToggle.getToggleStateValue() == 1));
        patch->flags = uint8_t(bendRangeUpSlider.getValue()
                               + (portamentoModeComboBox.getSelectedItemIndex() << 4)
                               + (soloLegatoToggle.getToggleState() << 5)
                               + (portamentoToggle.getToggleState() << 6)
                               + (keyAssignComboBox.getSelectedItemIndex() << 7));
        break;
    case ScaleTuneSwitch:
        processor.sendSysexParamChange(0x23, scaleTuneSwitch.getToggleStateValue() == 1);
        system->scaleTuneEnabled = uint8_t(scaleTuneSwitch.getToggleStateValue() == 1);
        break;
    default:
        break;
    }
}

void EditCommonTab::comboBoxChanged(juce::ComboBox* comboBox)
{
    uint32_t id = 0xFFFFFFF;

    if (auto i = dynamic_cast<Menu*>(comboBox))
    {
        id = i->getID();
    }

    auto patch = (Patch*) processor.status.patch;

    switch (id)
    {
    case ReverbType:
        sendSysexPatchCommonParamChange(0x0d, uint8_t(reverbTypeComboBox.getSelectedItemIndex()));
        patch->recChorConfig = uint8_t(reverbTypeComboBox.getSelectedItemIndex()
                                       + (chorusTypeComboBox.getSelectedItemIndex() << 4)
                                       + (velocitySwitchToggle.getToggleState() << 7));
        break;
    case ChorusType:
        sendSysexPatchCommonParamChange(0x11, uint8_t(chorusTypeComboBox.getSelectedItemIndex()));
        patch->recChorConfig = uint8_t(reverbTypeComboBox.getSelectedItemIndex()
                                       + (chorusTypeComboBox.getSelectedItemIndex() << 4)
                                       + (velocitySwitchToggle.getToggleState() << 7));
        break;
    case ChorusOutput:
        sendSysexPatchCommonParamChange(0x16, uint8_t(chorusOutputComboBox.getSelectedItemIndex()));
        patch->chorusLevel = uint8_t(chorusLevelSlider.getValue()
                                     + (chorusOutputComboBox.getSelectedItemIndex() << 7));
        break;
    case KeyAssign:
        sendSysexPatchCommonParamChange(0x1c, uint8_t(keyAssignComboBox.getSelectedItemIndex()));
        patch->flags = uint8_t(bendRangeUpSlider.getValue()
                               + (portamentoModeComboBox.getSelectedItemIndex() << 4)
                               + (soloLegatoToggle.getToggleState() << 5)
                               + (portamentoToggle.getToggleState() << 6)
                               + (keyAssignComboBox.getSelectedItemIndex() << 7));
        break;
    case PortamentoMode:
        sendSysexPatchCommonParamChange(0x1f, uint8_t(portamentoModeComboBox.getSelectedItemIndex()));
        patch->flags = uint8_t(bendRangeUpSlider.getValue()
                               + (portamentoModeComboBox.getSelectedItemIndex() << 4)
                               + (soloLegatoToggle.getToggleState() << 5)
                               + (portamentoToggle.getToggleState() << 6)
                               + (keyAssignComboBox.getSelectedItemIndex() << 7));
        break;
    case PortamentoType:
        sendSysexPatchCommonParamChange(0x20, uint8_t(portamentoTypeComboBox.getSelectedItemIndex()));
        patch->portamentoTime = uint8_t(portamentoTimeSlider.getValue()
                                        + (portamentoTypeComboBox.getSelectedItemIndex() << 7));
        break;
    default:
        break;
    }
}

void EditCommonTab::textEditorTextChanged (juce::TextEditor& textEditor)
{
    if (&textEditor == &patchNameEditor)
    {
        sendSysexPatchNameChange();
    }
}

void EditCommonTab::sendSysexPatchNameChange()
{
    auto patch = (Patch*) processor.status.patch;

    uint8_t buf[24];

    buf[0] = 0xf0;
    buf[1] = 0x41;
    buf[2] = 0x10; // unit number
    buf[3] = 0x46;
    buf[4] = 0x12; // command
    buf[5] = 0x00;
    buf[6] = 0x08;
    buf[7] = 0x20;
    buf[8] = 0x00;

    for (int i = 0; i < juce::jmin(MAX_PATCH_NAME_CHARS, patchNameEditor.getText().length()); i++)
    {
        buf[i + 9]     = patchNameEditor.getText()[i];
        patch->name[i] = patchNameEditor.getText()[i];
    }

    if (patchNameEditor.getText().length() < MAX_PATCH_NAME_CHARS)
    {
        for (int i = patchNameEditor.getText().length(); i < MAX_PATCH_NAME_CHARS; i++)
        {
            buf[i + 9]     = 0x20;
            patch->name[i] = 0x20;
        }
    }

    uint32_t checksum = 0;

    for (size_t i = 5; i < 21; i++)
    {
        checksum += buf[i];

        if (checksum >= 128)
            checksum -= 128;
    }

    checksum = 128 - checksum;

    buf[22] = (uint8_t)checksum;
    buf[23] = 0xf7;

    processor.mcuLock.enter();
    processor.mcu->postMidiSC55(buf, 24);
    processor.mcuLock.exit();
}

void EditCommonTab::sendSysexPatchCommonParamChange(const uint8_t address, const uint8_t value)
{
    uint8_t buf[12];

    buf[0] = 0xf0;
    buf[1] = 0x41;
    buf[2] = 0x10; // unit number
    buf[3] = 0x46;
    buf[4] = 0x12; // command
    buf[5] = 0x00;
    buf[6] = 0x08;
    buf[7] = 0x20;
    buf[8] = address;
    buf[9] = value;

    uint32_t checksum = 0;

    for (size_t i = 5; i < 10; i++)
    {
        checksum += buf[i];

        if (checksum >= 128)
           checksum -= 128;
    }

    checksum = 128 - checksum;

    buf[10] = (uint8_t)checksum;
    buf[11] = 0xf7;

    processor.mcuLock.enter();
    processor.mcu->postMidiSC55(buf, 12);
    processor.mcuLock.exit();
}