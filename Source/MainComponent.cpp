#include "MainComponent.h"

MainComponent::MainComponent()
{

}

MainComponent::~MainComponent()
{
    shutdownAudio();
}

void MainComponent::prepareToPlay (int samplesPerBlockExpected,
                                          double sampleRate)
{

}

void MainComponent::getNextAudioBlock (
    const juce::AudioSourceChannelInfo& bufferToFill)
{

}

void MainComponent::releaseResources()
{

}

void MainComponent::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);

    g.setColour(juce::Colours::white);
    g.setFont(30.0f);

    g.drawText("Hello JUCE!!",
               getLocalBounds(),
               juce::Justification::centred);
}

void MainComponent::resized()
{

}
