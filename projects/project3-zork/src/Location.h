#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <functional>
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
        std::vector<std::reference_wrapper<NPC> > get_npcs() const;
        std::vector<std::reference_wrapper<Item>>& get_items();

        bool get_visited() const;
        std::string get_name() const; 
        std::string get_description() const; 

        // Adders
        void add_location(const std::string& direction, Location* location);
        void add_npc(NPC& npc);
        void add_item(Item& item);

        bool remove_item(const std::string& item_name);
        
        // Set visited
        void set_visited();

        // Overloaded stream operator
        friend std::ostream& operator<<(std::ostream& os, const Location& location);

    private:
        std::string name;
        std::string description;
        bool visited = false;
        std::map<std::string, Location*> neighbors;
        std::vector<std::reference_wrapper<NPC> > npcs;
        std::vector<std::reference_wrapper<Item> > items;
};

#endif











