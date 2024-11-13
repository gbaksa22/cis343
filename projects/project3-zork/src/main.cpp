#include "AudioManager.hpp"
#include <vector>
#include <string>
#include <iostream>
#include "Item.h"
#include "NPC.h"
#include "Location.h"
#include "Game.h"

int main() {
    Game game;
    game.play();
    return 0;

    /*
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
    */
}
