
cmake_minimum_required(VERSION 3.22)

project(JUCE_template VERSION 1.0)

# Import JUCE framework
add_subdirectory(JUCE)

# Create standalone application
juce_add_gui_app(JUCE_test
        PRODUCT_NAME "JUCE Template"
)

# Source files
target_sources(JUCE_test
        PRIVATE
        Source/Main.cpp
        Source/MainComponent.cpp
)

# Link JUCE modules
target_link_libraries(JUCE_test
        PRIVATE
        juce::juce_audio_utils
        juce::juce_gui_extra
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)
