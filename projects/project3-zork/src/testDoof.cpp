#include "NPC.h"
#include "AudioManager.hpp"
#include <iostream>
#include <vector>

int main() {
    // Create an NPC for Doofenshmirtz with a description
    NPC doof("Doofenshmirtz", "Evil scientist always trying to defeat Perry the Platypus.");

    // Add audio files for Doofenshmirtz
    doof.add_audio_file("Unexpected Surprise", "../audio/npcs/doofenshmirtz/doof1-unexpected-surprise.wav");
    doof.add_audio_file("Evil Plan", "../audio/npcs/doofenshmirtz/doof2-evil-plan.wav");
    doof.add_audio_file("Pizza Delivery Guy", "../audio/npcs/doofenshmirtz/doof3-pizza-delivery-guy.wav");
    doof.add_audio_file("Getting Warmer", "../audio/npcs/doofenshmirtz/doof4-getting-warmer.wav");
    doof.add_audio_file("Red Button", "../audio/npcs/doofenshmirtz/doof5-red-button.wav");

    // Initialize AudioManager with paths from the NPC
    std::vector<std::string> audioPaths = doof.get_audio_paths();
    AudioManager audioManager(audioPaths);

    // Initialize the audio engine
    if (!audioManager.init()) {
        std::cerr << "Failed to initialize audio manager." << std::endl;
        return -1;
    }

    // Play sounds in sequence with the ability to stop each sound before playing the next
    for (size_t i = 0; i < audioPaths.size(); ++i) {
        audioManager.playSound(audioPaths[i]);
        std::cout << "Playing sound: " << audioPaths[i] << "\n";
        std::cout << "Press Enter to stop and play the next sound...";
        std::cin.get();
        
        // Stop the current sound before moving to the next one
        audioManager.stopSound();
    }

    // Test playing a specific sound by name
    doof.play_audio("Evil Plan", audioManager);  // Play by name
    std::cout << "Press Enter to stop the sound...";
    std::cin.get();
    audioManager.stopSound();
    
    // Clean up the audio engine
    audioManager.cleanup();

    return 0;
}
