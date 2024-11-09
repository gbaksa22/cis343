#include "AudioManager.hpp"
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<std::string> npcSounds;
    npcSounds.push_back("./audio/doofenshmirtz/doofenshmirtz-evil-incorporated-jingle.wav");
    npcSounds.push_back("./audio/doofenshmirtz/getting-warmer.wav");
    npcSounds.push_back("./audio/doofenshmirtz/perry-the-platypus.wav");
    npcSounds.push_back("./audio/doofenshmirtz/red-button.wav");

    AudioManager npcAudioManager(npcSounds);

    if (!npcAudioManager.init()) {
        return -1;
    }

    npcAudioManager.playRandomSound();

    std::cout << "Press Enter to quit...";
    std::cin.get();

    npcAudioManager.cleanup();

    return 0;
}
