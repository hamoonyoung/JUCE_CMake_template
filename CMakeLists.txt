cmake_minimum_required(VERSION 3.22)

set(app_name "APP_NAME")
set(product_name "PRODUCT_NAME")

project(${app_name} VERSION 1.0)

# Import JUCE framework
add_subdirectory(JUCE)

# Create standalone application
juce_add_gui_app(${app_name}
        PRODUCT_NAME "${product_name}"
)

# Generate JUCE header
juce_generate_juce_header(${app_name})

# Source files
target_sources(${app_name}
        PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/Main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/Source/MainComponent.cpp"
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
        juce::juce_gui_extra
        juce::juce_recommended_lto_flags
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)
