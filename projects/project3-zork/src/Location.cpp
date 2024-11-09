#include "Location.h"
#include <iostream>

// Constructor
Location::Location(const std::string& name, const std::string& description) {
    this->name = name;
    this->description = description;
}

// Getters
std::map<std::string, Location*> Location::get_locations() const {
    return neighbors;
}

std::vector<std::reference_wrapper<NPC>> Location::get_npcs() const {
    return npcs;
}

std::vector<std::reference_wrapper<Item>> Location::get_items() const {
    return items;
}

bool Location::get_visited() const {
    return visited;
}

// Add location
void Location::add_location(const std::string& direction, Location* location) {
    if (direction.empty()) {
        std::cout << "Error: Direction cannot be blank.\n";
        return;
    }
    if (neighbors.find(direction) != neighbors.end()) {
        std::cout << "Error: This direction already exists.\n";
        return;
    }
    neighbors[direction] = location;
}

// Add an NPC
void Location::add_npc(NPC& npc) {
    npcs.push_back(std::ref(npc)); // wrap the NPC reference
}

// Add an Item
void Location::add_item(Item& item) {
    items.push_back(std::ref(item)); // wrap the Item reference
}

// Mark location as visited
void Location::set_visited() {
    visited = true;
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << location.name << " - " << location.description << "\n";

    // Display NPCs
    os << "You see the following NPCs:\n";
    if (location.npcs.empty()) {
        os << " - None\n";
    } else {
        for (const auto& npc : location.npcs) {
            os << " - " << npc.get() << "\n";
        }
    }

    // Display Items
    os << "You see the following Items:\n";
    if (location.items.empty()) {
        os << " - None\n";
    } else {
        for (const auto& item : location.items) {
            os << " - " << item.get() << "\n";
        }
    }

    // Display Neighbors
    os << "You can go in the following Directions:\n";
    for (const auto& [direction, loc] : location.neighbors) {
        os << " - " << direction << " - " << loc->name;
        if (loc->get_visited()) {
            os << " (Visited)";
        }
        os << "\n";
    }

    return os;
}

