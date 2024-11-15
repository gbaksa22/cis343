#include "Location.h"
#include <iostream>
#include <algorithm>


// Constructor
Location::Location(const std::string& name, const std::string& description) {
    this->name = name;
    this->description = description;
}

// Getters
std::map<std::string, Location*> Location::get_locations() const {
    return neighbors;
}

std::vector<std::reference_wrapper<NPC> > Location::get_npcs() const {
    return npcs;
}

std::vector<std::reference_wrapper<Item>>& Location::get_items() {
    return items;
}


bool Location::get_visited() const {
    return visited;
}

std::string Location::get_name() const {
    return name;
}

std::string Location::get_description() const {
    return description;
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
    npcs.push_back(std::ref(npc));
}

// Add an Item
void Location::add_item(Item& item) {
    items.push_back(std::ref(item));
}

// Remove an Item
bool Location::remove_item(const std::string& item_name) {
    // Find the item in the location's inventory using its name.
    auto item_iterator = std::find_if(items.begin(), items.end(),
                                      [&](const std::reference_wrapper<Item>& item) {
                                          return item.get().get_name() == item_name;
                                      });

    // If the item is not found, return false.
    if (item_iterator == items.end()) {
        return false;
    }

    // Remove the item from the inventory.
    items.erase(item_iterator);
    return true;
}


// Mark location as visited
void Location::set_visited() {
    visited = true;
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << location.name << " - " << location.description << "\n\n";

    // Display NPCs
    os << "You see the following NPCs:\n";
    if (location.npcs.empty()) {
        os << " - None\n\n";
    } else {
        for (const auto& npc : location.npcs) {
            os << " - " << npc.get() << "\n\n";
        }
    }

    // Display Items
    os << "You see the following Items:\n";
    if (location.items.empty()) {
        os << " - None\n\n";
    } else {
        for (const auto& item : location.items) {
            os << " - " << item.get() << "\n\n";
        }
    }

    // Display Neighbors
    os << "You can go in the following Directions:\n";
    for (const auto& pair : location.neighbors) {
        const std::string& direction = pair.first;
        Location* loc = pair.second;

        // Check if the location has been visited
        os << " - " << direction << " - ";
        if (loc->get_visited()) {
            os << loc->name << " (Visited)";
        } else {
            os << "Unknown";
        }

        os << "\n";
    }


    return os;
}

