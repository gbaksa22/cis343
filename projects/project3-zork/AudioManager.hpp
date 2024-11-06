#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SFML/Audio.hpp>
#include <string>
#include <vector>

class AudioManager {
public:
    // Function to play random audio for an NPC
    void playAudioForNPC(const std::string& npcName);

    // Function to play random audio for a location
    void playAudioForLocation(const std::string& location);

private:
    // Helper function to load all audio files from a directory and play one
    void playRandomAudioFromDir(const std::string& directory);
};

#endif // AUDIOMANAGER_HPP
