cmake_minimum_required(VERSION 3.22)

project(JUCE_template VERSION 1.0)

set(app_name "APP_NAME")
set(product_name "PRODUCT_NAME")
# Import JUCE framework
add_subdirectory(JUCE)

# Create standalone application
juce_add_gui_app(${app_name}
        PRODUCT_NAME ${product_name}
)

# Source files
target_sources(${app_name}
        PRIVATE
        Source/Main.cpp
        Source/MainComponent.cpp
)

# Link JUCE modules
target_link_libraries(${app_name}
        PRIVATE
        juce::juce_audio_utils
        juce::juce_gui_extra
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)
