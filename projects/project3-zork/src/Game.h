#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include <map>
#include "Location.hpp"
#include "Item.hpp"
#include "NPC.hpp"

class Game {
public:
    // Constructor
    Game();

    // Core game loop
    void play();

    // Command setup and world creation
    std::map<std::string, void(*)(std::vector<string>)> setup_commands();
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

private:
    std::map<std::string, void(*)(std::vector<string>)> commands;
    std::vector<Item> inventory;
    int current_weight = 0;
    std::vector<Location> locations;
    Location* current_location;
    int needed_parts = 4; 
    bool game_in_progress = true;
};

#endif
