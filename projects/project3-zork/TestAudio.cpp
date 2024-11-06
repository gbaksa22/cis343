#include <SFML/Audio.hpp>
#include <iostream>
#include "AudioManager.hpp"

int main() {
    AudioManager audioManager;

    // Test with a single NPC "Perry"
    std::cout << "Testing audio for Perry..." << std::endl;
    audioManager.playAudioForNPC("perry");

    return 0;
}
