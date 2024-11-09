#ifndef NPC_H
#define NPC_H

#include <string>
#include <vector>
#include <iostream>

class NPC {
public:
    // Constructor
    NPC(const std::string& name, const std::string& description);

    // Getters
    std::string get_name() const;
    std::string get_description() const;
    std::string get_message();

    // Overloaded stream operator
    friend std::ostream& operator<<(std::ostream& os, const NPC& npc);

    // Add a message
    void add_message(const std::string& message);

private:
    std::string name;
    std::string description;
    std::vector<std::string> messages;
    int message_number = 0;
};

#endif 
