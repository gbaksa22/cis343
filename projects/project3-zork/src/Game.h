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
        std::map<std::string, void(*)(std::vector<std::string>)> setup_commands();
        void create_world();

        // Command functions
        void show_help();
        void talk(std::vector<std::string> target);
        void meet(std::vector<std::string> target);
        void take(std::vector<std::string> target);
        void give(std::vector<std::string> target);
        void go(std::vector<std::string> target);
        void show_items(std::vector<std::string> target);
        void look(std::vector<std::string> target);
        void quit(std::vector<std::string> target);
        void build(std::vector<std::string> target);

        void test_play_audio();

    private:
        std::map<std::string, void(*)(std::vector<std::string>)> commands;
        std::vector<Item> inventory;
        std::vector<Location> locations;
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
};

#endif
