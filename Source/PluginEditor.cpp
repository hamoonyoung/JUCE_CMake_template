#include "PluginEditor.h"

PluginEditor::PluginEditor(PluginProcessor& p)
    : AudioProcessorEditor(&p),
      audioProcessor(p)
{
    setSize(400, 300);
}

PluginEditor::~PluginEditor()
{
}

void PluginEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(35, 35, 35));

    g.setColour(juce::Colours::white);

    g.setFont(24.0f);

    g.drawFittedText(
        JucePlugin_Name,
        getLocalBounds(),
        juce::Justification::centred,
        1
    );
}

void PluginEditor::resized()
{
    // Position GUI components here.
}
