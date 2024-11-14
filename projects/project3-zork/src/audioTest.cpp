#include "AudioManager.hpp"
#include <vector>
#include <string>
#include <iostream>

int main() {
    // Define paths to the audio files
    std::vector<std::string> npcSounds;
    npcSounds.push_back("../audio/npcs/doofenshmirtz/doof1-unexpected-surprise.wav");
    npcSounds.push_back("../audio/npcs/doofenshmirtz/doof2-evil-plan.wav");
    npcSounds.push_back("../audio/npcs/doofenshmirtz/doof3-pizza-delivery-guy.wav");
    npcSounds.push_back("../audio/npcs/doofenshmirtz/doof4-getting-warmer.wav");
    npcSounds.push_back("../audio/npcs/doofenshmirtz/doof5-red-button.wav");

    // Initialize the audio manager with the audio file paths
    AudioManager npcAudioManager(npcSounds);

    // Initialize the audio engine
    if (!npcAudioManager.init()) {
        std::cerr << "Failed to initialize audio manager." << std::endl;
        return -1;
    }

    // Play a random sound from the list
    npcAudioManager.playSound(npcSounds[0]);
    std::cout << "Playing 0\n";

    std::cout << "Press Enter to quit...";
    std::cin.get();

    npcAudioManager.playSound(npcSounds[1]);
    std::cout << "Playing 1\n";

    std::cout << "Press Enter to quit...";
    std::cin.get();

    // Clean up the audio engine
    npcAudioManager.cleanup();

    return 0;
}
