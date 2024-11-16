#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include "Location.h"
#include "Item.h"
#include "NPC.h"
#include "AudioManager.hpp"

class Game {
    public:
        // Constructor
        Game();

        // Core game loop
        void play();

        // Command setup and world creation
        //std::map<std::string, void(*)(std::vector<std::string>)> setup_commands();
        std::map<std::string, std::function<void(std::vector<std::string>)>> setup_commands();


        void create_world();

        // Command functions
        void show_help();
        void talk(std::vector<std::string> target);
        void meet(std::vector<std::string> target);
        void take(std::vector<std::string> target);
        void drop(std::vector<std::string> target);
        void go(std::vector<std::string> target);
        void look(std::vector<std::string> target);
        void give(std::vector<std::string> target);
        void quit(std::vector<std::string> target);
        void show_inventory(std::vector<std::string> target);

    private:
        //std::map<std::string, void(*)(std::vector<std::string>)> commands;
        std::map<std::string, std::function<void(std::vector<std::string>)>> commands;

        std::vector<Item> inventory;
        std::vector<Location> locations;
        int weight = 0;
        Location* current_location;
        int needed_parts = 5; 
        bool game_in_progress = true;

        Location flynnFletcherResidence;
        Location backyardWorkshop;
        Location doofenshmirtzEvilInc;
        Location constructionSite;
        Location baljeetHouse;
        Location bufordHouse;
        Location danvillePark;
        Location secretLair;

        NPC phineas;
        NPC candace;
        NPC constructionWorker;
        NPC drDoofenshmirtz;
        NPC majorMonogram;
        
        Item blowtorch;
        Item peanutButter;
        Item wrench;
        Item roboMachine;
        Item computerChip;
        Item blueprints;

        int level = 1; // Tracks the current level for giving items in order
        std::vector<std::string> required_items = {
            "Blowtorch",
            "Peanut Butter",
            "Wrench",
            "Robo Machine",
            "Computer Chip",
            "Blueprints"
        };
};

#endif
