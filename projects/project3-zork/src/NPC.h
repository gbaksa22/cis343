#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>
#include "AudioManager.hpp"

class NPC {
public:
    // Struct to hold name and path of audio files
    struct AudioEntry {
        std::string name;
        std::string path;
    };

    // Constructor
    NPC(const std::string& name, const std::string& description);

    // Getters
    std::string get_name() const;
    std::string get_description() const;
    std::string get_message();
    std::vector<std::string> get_audio_paths() const; // Getter for audio paths

    // Overloaded stream operator
    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);

    // Add a message
    void add_message(const std::string& message);

    // Audio-related functions
    void add_audio_file(const std::string& name, const std::string& filePath);
    void play_audio(const std::string& name, AudioManager& audioManager);

private:
    std::string name;
    std::string description;
    std::vector<std::string> messages;
    int message_number = 0;

    std::vector<AudioEntry> audioFiles; // Vector of named audio files
};

#endif
