# JUCE CMake Template

This is a CMake template designed to help you get started with JUCE projects quickly.

Since this template does not include the JUCE framework itself, you will need to download it separately. I recommend keeping a copy of JUCE inside each project directory. This way, you won't have to worry about framework paths when switching development environments or platforms.

### 1. Download JUCE

Open a terminal in the root directory of your project and run:

```bash
git clone https://github.com/juce-framework/JUCE.git
```

This will download the JUCE framework into a `JUCE` subdirectory within your project.

### 2. Reload CMake

Once the download is complete, reload your CMake project so that CMake can detect and configure the JUCE framework.

### 3. Customize Your Application

Make sure to update `app_name` and `product_name` in your CMake configuration to match your application.
