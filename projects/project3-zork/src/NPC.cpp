#include "NPC.h"
#include <iostream>

// Constructor
NPC::NPC(const std::string& name, const std::string& description) {
    if (name.empty()) {
        std::cout << "Error: NPC name is blank.\n";
        this->name = "Unnamed NPC";
    } else {
        this->name = name;
    }

    if (description.empty()) {
        std::cout << "Error: NPC description is blank.\n";
        this->description = "No description";
    } else {
        this->description = description;
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

// Add a single audio file with a name
void NPC::add_audio_file(const std::string& name, const std::string& filePath) {
    audioFiles.push_back({name, filePath});
}

// Get audio paths for initialization in AudioManager
std::vector<std::string> NPC::get_audio_paths() const {
    std::vector<std::string> paths;
    for (const auto& entry : audioFiles) {
        paths.push_back(entry.path);
    }
    return paths;
}
