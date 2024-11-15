#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <vector>
#include <string>
#include "miniaudio.h"  // Ensure miniaudio is included correctly

class AudioManager {
public:
    AudioManager(); // Default constructor for cases without initial audio files
    AudioManager(const std::vector<std::string>& audioFiles); // Constructor with audio files

    // Initializes the audio engine
    bool init();

    // Plays a specific audio file
    void playSound(const std::string& soundPath);

    // Stops the currently playing sound
    void stopSound();

    // Cleans up the audio engine
    void cleanup();

private:
    ma_engine engine;
    ma_sound currentSound;
    bool currentSoundInitialized; 
    std::vector<std::string> audioFiles;
};

#endif // AUDIOMANAGER_HPP
