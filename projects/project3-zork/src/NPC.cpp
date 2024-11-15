#include "NPC.h"
#include <iostream>

// Constructor
NPC::NPC(const std::string& name, const std::string& description)
    : name(name.empty() ? "Unnamed NPC" : name),
      description(description.empty() ? "No description" : description),
      audioManager() // Initialize AudioManager
{
    if (name.empty()) {
        std::cout << "Error: NPC name is blank.\n";
    }
    if (description.empty()) {
        std::cout << "Error: NPC description is blank.\n";
    }
}

// Getters
std::string NPC::get_name() const {
    return name;
}

std::string NPC::get_description() const {
    return description;
}

std::string NPC::get_message() {
    if (messages.empty()) {
        return "No messages available.";
    }

    std::string current_message = messages[message_number];
    message_number = (message_number + 1) % messages.size();

    return current_message;
}

// Add a message
void NPC::add_message(const std::string& message) {
    if (message.empty()) {
        std::cout << "Error: Message cannot be blank. Message not added.\n";
    } else {
        messages.push_back(message);
    }
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const NPC& npc) {
    os << npc.name;
    return os;
}
// Add an audio file by name and path
void NPC::add_audio_file(const std::string& name, const std::string& filePath) {
    audioFiles.push_back({name, filePath});
    audioManager = AudioManager(get_audio_paths()); // Reinitialize AudioManager with updated paths
}

// Play audio by name
void NPC::play_audio(const std::string& name) {
    if (!audioManager.init()) {  // Ensure AudioManager is initialized
        std::cerr << "Error: Failed to initialize AudioManager for NPC: " << name << "\n";
        return;
    }

    for (const auto& entry : audioFiles) {
        if (entry.name == name) {
            audioManager.playSound(entry.path);  // Play the audio file
            std::cout << "Playing sound: " << name << "\n";
            return;
        }
    }

    std::cerr << "Error: Audio file with name '" << name << "' not found for NPC: " << get_name() << "\n";
}


// Helper function to get all audio paths for AudioManager initialization
std::vector<std::string> NPC::get_audio_paths() const {
    std::vector<std::string> paths;
    for (const auto& entry : audioFiles) {
        paths.push_back(entry.path);
    }
    return paths;
}
