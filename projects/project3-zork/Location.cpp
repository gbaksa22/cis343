#include "Location.h"

Location::Location(std::string name, std::string description)

// Getters
std::map<std::string, Location> Location::get_locations() {
    return neighbors;
}

std::vector<NPC> Location::get_npcs() {
    return npcs;
}

std::vector<Item> Location::get_items() {
    return items;
}

bool Location::get_visited() {
    return visited;
}

// Adders
void Location::add_location(std::string direction, Location location) {
    neighbors[direction] = location;
}



