
cmake_minimum_required(VERSION 3.22)

# Project settings
set(app_name "APP_NAME")
set(product_name "PRODUCT_NAME")
set(company_name "COMPANY_NAME")

set(manufacturer_code "MACD")  # Exactly 4 characters
set(plugin_code "PICD")        # Exactly 4 characters

project(${app_name} VERSION 1.0.0)

# Import JUCE framework
add_subdirectory(JUCE)

# Plugin formats
set(plugin_formats VST3 Standalone)

if(APPLE)
    list(APPEND plugin_formats AU)
endif()

# Create plugin
juce_add_plugin(${app_name}
        COMPANY_NAME "${company_name}"
        PLUGIN_MANUFACTURER_CODE ${manufacturer_code}
        PLUGIN_CODE ${plugin_code}

        FORMATS ${plugin_formats}
        PRODUCT_NAME "${product_name}"

        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT FALSE
        NEEDS_MIDI_OUTPUT FALSE
        IS_MIDI_EFFECT FALSE

        EDITOR_WANTS_KEYBOARD_FOCUS FALSE
        COPY_PLUGIN_AFTER_BUILD FALSE

        VST3_CATEGORIES Fx
        AU_MAIN_TYPE kAudioUnitType_Effect
)

# Generate JUCE header
juce_generate_juce_header(${app_name})

# Source files
target_sources(${app_name}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/PluginProcessor.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/PluginProcessor.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/PluginEditor.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/PluginEditor.h"
)

# Include directories
target_include_directories(${app_name}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Source"
)

# Link JUCE modules
target_link_libraries(${app_name}
        PRIVATE
        juce::juce_audio_utils

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)
