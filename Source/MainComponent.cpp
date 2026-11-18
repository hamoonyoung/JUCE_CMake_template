#include "MainComponent.h"

MainComponent::MainComponent()
{
    setSize(600, 400);
}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(30.0f);

    g.drawText("Hello JUCE!",
               getLocalBounds(),
               juce::Justification::centred);
}

void MainComponent::resized()
{
}
