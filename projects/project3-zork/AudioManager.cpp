#include "AudioManager.hpp"
#include <iostream>
#include <filesystem>
#include <random>

namespace fs = std::filesystem;

void AudioManager::playAudioForNPC(const std::string& npcName) {
    std::string npcDirectory = "audio/" + npcName + "/"; // Path to the NPC's audio files
    playRandomAudioFromDir(npcDirectory);
}

void AudioManager::playAudioForLocation(const std::string& location) {
    std::string locationDirectory = "audio/" + location + "/"; // Path to the location's audio files
    playRandomAudioFromDir(locationDirectory);
}

void AudioManager::playRandomAudioFromDir(const std::string& directory) {
    std::vector<std::string> audioFiles;

    // Check if the directory exists
    if (!fs::exists(directory)) {
        std::cerr << "Error: Directory " << directory << " does not exist." << std::endl;
        return;
    }

    // Iterate through all files in the directory
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.is_regular_file() && entry.path().extension() == ".mp3") {
            audioFiles.push_back(entry.path().string());
        }
    }

    // If no audio files are found, print an error and return
    if (audioFiles.empty()) {
        std::cerr << "Error: No audio files found in directory " << directory << std::endl;
        return;
    }

    // Randomly select an audio file
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, audioFiles.size() - 1);

    // Play the selected audio file
    std::string selectedFile = audioFiles[dist(gen)];
    sf::Music music;
    if (!music.openFromFile(selectedFile)) {
        std::cerr << "Error: Could not load audio file " << selectedFile << std::endl;
        return;
    }
    music.play();
    while (music.getStatus() == sf::Music::Playing) {
        // Keep the program running while the music is playing
    }
}
