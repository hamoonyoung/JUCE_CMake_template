#include "PluginProcessor.h"
#include "PluginEditor.h"

PluginProcessor::PluginProcessor()
    : AudioProcessor(
        BusesProperties()
            .withInput("Input",
                       juce::AudioChannelSet::stereo(),
                       true)
            .withOutput("Output",
                        juce::AudioChannelSet::stereo(),
                        true)
    )
{
}

PluginProcessor::~PluginProcessor()
{
}

void PluginProcessor::prepareToPlay(
    double sampleRate,
    int samplesPerBlock)
{
    // Initialize DSP here.
}

void PluginProcessor::releaseResources()
{
    // Release DSP resources here.
}

bool PluginProcessor::isBusesLayoutSupported(
    const BusesLayout& layouts) const
{
    const auto input = layouts.getMainInputChannelSet();
    const auto output = layouts.getMainOutputChannelSet();

    if (input != output)
        return false;

    return input == juce::AudioChannelSet::mono()
        || input == juce::AudioChannelSet::stereo();
}

void PluginProcessor::processBlock(
    juce::AudioBuffer<float>& buffer,
    juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;

    // Clear any output channels without corresponding inputs.
    for (int channel = getTotalNumInputChannels();
         channel < getTotalNumOutputChannels();
         ++channel)
    {
        buffer.clear(channel, 0, buffer.getNumSamples());
    }

    // Audio processing goes here.
    // Currently, the plugin passes audio through unchanged.
}

juce::AudioProcessorEditor*
PluginProcessor::createEditor()
{
    return new PluginEditor(*this);
}

bool PluginProcessor::hasEditor() const
{
    return true;
}

const juce::String PluginProcessor::getName() const
{
    return JucePlugin_Name;
}

bool PluginProcessor::acceptsMidi() const
{
    return false;
}

bool PluginProcessor::producesMidi() const
{
    return false;
}

bool PluginProcessor::isMidiEffect() const
{
    return false;
}

double PluginProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

// Programs

int PluginProcessor::getNumPrograms()
{
    return 1;
}

int PluginProcessor::getCurrentProgram()
{
    return 0;
}

void PluginProcessor::setCurrentProgram(int index)
{
}

const juce::String PluginProcessor::getProgramName(int index)
{
    return {};
}

void PluginProcessor::changeProgramName(
    int index,
    const juce::String& newName)
{
}

// State management

void PluginProcessor::getStateInformation(
    juce::MemoryBlock& destData)
{
}

void PluginProcessor::setStateInformation(
    const void* data,
    int sizeInBytes)
{
}

// Plugin entry point

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new PluginProcessor();
}
