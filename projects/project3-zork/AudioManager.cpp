#define MINIAUDIO_IMPLEMENTATION
#include "AudioManager.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

AudioManager::AudioManager(const std::vector<std::string>& audioPaths)
    : audioFiles(audioPaths)
{
    // Seed the random number generator
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
    // Play the specified sound
    if (ma_engine_play_sound(&engine, soundPath.c_str(), NULL) != MA_SUCCESS) {
        std::cerr << "Failed to play sound: " << soundPath << std::endl;
    } else {
        std::cout << "Playing: " << soundPath << std::endl;
    }
}

void AudioManager::playRandomSound() {
    // Shuffle and select a random sound
    std::random_shuffle(audioFiles.begin(), audioFiles.end());
    if (!audioFiles.empty()) {
        playSound(audioFiles[0]);
    }
}

void AudioManager::cleanup() {
    ma_engine_uninit(&engine);
}
