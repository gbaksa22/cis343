#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <vector>
#include <string>
#include "miniaudio.h"  // Ensure miniaudio is included correctly

class AudioManager {
public:
    // Constructor takes a vector of audio file paths
    AudioManager(const std::vector<std::string>& audioPaths);

    // Initializes the audio engine
    bool init();

    // Plays a specific audio file
    void playSound(const std::string& soundPath);

    // Shuffles and plays a random audio file
    void playRandomSound();

    // Cleans up the audio engine
    void cleanup();

private:
    ma_engine engine;
    std::vector<std::string> audioFiles;
};

#endif // AUDIOMANAGER_HPP
