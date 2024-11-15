#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include "AudioManager.hpp"

class NPC {
public:
    struct AudioEntry {
        std::string name;
        std::string path;
    };

    // Constructor
    NPC(const std::string& name, const std::string& description);

    // Overloaded operator<< for NPC
    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);


    // Getters
    std::string get_name() const;
    std::string get_description() const;
    std::string get_message();
    std::vector<std::string> get_audio_paths() const; // Getter for audio paths

    void play_next();

    // Add message and audio
    void add_message(const std::string& message);
    void add_audio_file(const std::string& name, const std::string& filePath);

    // Play audio by name
    void play_audio(const std::string& name);

    // Stop audio that is currently playing
    void stop_audio();


private:
    std::string name;
    std::string description;
    std::vector<std::string> messages;
    int message_number = 0;
    size_t index = 0; // Index for tracking audio files

    AudioManager audioManager; // Internal AudioManager instance
    std::vector<AudioEntry> audioFiles;
};

#endif
