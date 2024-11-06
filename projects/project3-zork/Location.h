#ifndef LOCATION_H
#define LOCATION_H

#include "NPC.h"
#include "Item.h"

class Location {
    public:
        // Constructor
        Location(std::string name, std::string description);

        // Getters
        std::map<string, Location> get_locations();
        std::vector<NPC> get_npcs();
        std::vector<Item> get_items();

        // Adders
        void add_location(string direction, Location location);
        void add_npc(NPC npc);
        void add_item(Item item);


        void set_visited();

    private:

}




#endif
