# JUCE CMake Template

A CMake template designed to help you quickly get started with JUCE projects.

## Standalone Application & Plugin

This repository provides two branches for different project configurations:

- **`main` branch:** Configured to build a standalone application.\

```bash
git clone https://github.com/hamoonyoung/JUCE_CMake_template.git
```
  
- **`plugin` branch:** Configured to build audio plugins (VST3, AU, etc.). You can also build a standalone application from this branch.

```bash
git clone -b plugin --single-branch https://github.com/hamoonyoung/JUCE_CMake_template.git
```

## How to Use

This template does not include the JUCE framework itself, so you will need to download it separately.

I recommend keeping a local copy of JUCE inside each project directory. This makes the project more portable and avoids having to manage framework paths when switching between development environments or platforms.

### 1. Download JUCE

Open a terminal in the root directory of your project and run:

```bash
git clone https://github.com/juce-framework/JUCE.git
```

This downloads the JUCE framework into a `JUCE` subdirectory within your project.

Your project directory should look something like this:

```text
YourProject/
├── JUCE/
├── CMakeLists.txt
├── Source/
└── ...
```

### 2. Reload CMake

Once the download is complete, reload your CMake project so that CMake can detect and configure the JUCE framework.

In CLion, you can reload the CMake project from the CMake tool window or by using **Tools → CMake → Reload CMake Project**.

### 3. Customize Your Application

Update `app_name` and `product_name` in your CMake configuration to match your application.

- `app_name`: The application or project name used in your build configuration.
- `product_name`: The name displayed to users in the built application or plugin.

Make sure these values are consistent with your intended project name.
