#define MINIAUDIO_IMPLEMENTATION
#include "AudioManager.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

AudioManager::AudioManager()
    : currentSoundInitialized(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

AudioManager::AudioManager(const std::vector<std::string>& audioFiles)
    : audioFiles(audioFiles), currentSoundInitialized(false) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

bool AudioManager::init() {
    if (ma_engine_init(NULL, &engine) != MA_SUCCESS) {
        std::cerr << "Failed to initialize audio engine." << std::endl;
        return false;
    }
    return true;
}

void AudioManager::playSound(const std::string& soundPath) {
    // Stop any currently playing sound
    stopSound();

    // Initialize and play the specified sound
    if (ma_sound_init_from_file(&engine, soundPath.c_str(), 0, NULL, NULL, &currentSound) != MA_SUCCESS) {
        std::cerr << "Failed to load sound: " << soundPath << std::endl;
        currentSoundInitialized = false;
    } else {
        currentSoundInitialized = true;
        if (ma_sound_start(&currentSound) != MA_SUCCESS) {
            std::cerr << "Failed to play sound: " << soundPath << std::endl;
            ma_sound_uninit(&currentSound);
            currentSoundInitialized = false;
        }
    }
}

void AudioManager::stopSound() {
    if (currentSoundInitialized) {
        ma_sound_stop(&currentSound);
        ma_sound_uninit(&currentSound);
        currentSoundInitialized = false;
    }
}

void AudioManager::cleanup() {
    stopSound();  // Ensure any playing sound is stopped and cleaned up
    ma_engine_uninit(&engine);
}
