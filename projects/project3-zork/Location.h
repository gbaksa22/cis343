#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "NPC.h"
#include "Item.h"

class Location {
    public:
        // Constructor
        Location(const std::string& name, const std::string& description);

        // Getters
        std::map<std::string, Location*> get_locations() const;
        std::vector<NPC> get_npcs() const;
        std::vector<Item> get_items() const;
        bool get_visited() const;

        // Addders
        void add_location(const std::string& direction, Location* location);
        void add_npc(const NPC& npc);
        void add_item(const Item& item);
        
        // Set visited
        void set_visited();

        // Overloaded stream operator
        friend std::ostream& operator<<(std::ostream& os, const Location& location);

    private:
        std::string name;
        std::string description;
        bool visited = false;
        std::map<std::string, Location*> neighbors;
        std::vector<NPC> npcs;
        std::vector<Item> items;
};

#endif



