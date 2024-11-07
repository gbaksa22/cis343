#include <SDL2/SDL.h>
#include "AudioManager.hpp"
#include <iostream>

int main() {
    AudioManager audioManager;

    // Test with an NPC "Perry"
    std::cout << "Testing audio for Perry..." << std::endl;
    audioManager.playAudioForNPC("perry");

    return 0;
}
