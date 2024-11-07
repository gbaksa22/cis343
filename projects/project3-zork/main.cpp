#include "AudioManager.hpp"
#include <iostream>

int main() {
    AudioManager audioManager;

    if (!audioManager.initialize()) {
        std::cerr << "Failed to initialize audio manager." << std::endl;
        return -1;
    }

    if (!audioManager.loadWAV("theme-song.wav")) {
        std::cerr << "Failed to load audio file." << std::endl;
        return -1;
    }

    audioManager.play();

    // Wait for the duration of the audio
    SDL_Delay(3000); // Adjust based on audio length or add a function to calculate it

    audioManager.cleanup();

    return 0;
}
