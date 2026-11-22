#pragma once

#include <JuceHeader.h>

class PluginProcessor : public juce::AudioProcessor
{
public:
    PluginProcessor();

    ~PluginProcessor() override;

    // Audio processing
    void prepareToPlay(double sampleRate,
                       int samplesPerBlock) override;

    void releaseResources() override;

    void processBlock(juce::AudioBuffer<float>&,
                      juce::MidiBuffer&) override;

    // Bus layout
    bool isBusesLayoutSupported(
        const BusesLayout& layouts) const override;

    // Editor
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    // Plugin information
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;

    double getTailLengthSeconds() const override;

    // Programs
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram(int index) override;
    const juce::String getProgramName(int index) override;
    void changeProgramName(int index,
                           const juce::String& newName) override;

    // State management
    void getStateInformation(
        juce::MemoryBlock& destData) override;

    void setStateInformation(
        const void* data,
        int sizeInBytes) override;

private:

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProcessor)
};
