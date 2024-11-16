#include "Game.h"
#include <iostream>
#include <sstream>
#include <sstream>
#include <algorithm>
#include <csignal>
/*
TODO:

Add audio for game class:
- play_audio
- stop_audio
- init()
- cleanup()

Use game class audio for start game
- theme song
- i know what we're gonna do today

Use game class audio for end game
- ladies and gentlemen - coolest coaster ever
- ride roller coaster

Use game class audio for entering doofs room and secret lair
- doobee dobee doo
- doofenshmirtz evil incorporated

Aliases for directions
- n, e, s, w

Make it so case doesn't matter
- use a lowercase() function
*/


// Global variable for accessing the game instance
Game* gameInstance = nullptr;

// Signal handler for SIGINT (Ctrl+C)
void handle_signal(int signal) {
    if (signal == SIGINT && gameInstance != nullptr) {
        std::cout << "\nCtrl+C detected. Exiting the game...\n";
        gameInstance->quit({}); // Call the quit command
    }
}

// Constructor
Game::Game()
    : backyardWorkshop("Backyard Workshop", "The creative hub where Phineas and Ferb bring their wild ideas to life. It's filled with tools, gadgets, and half-finished projects - the perfect place for big inventions."),
      flynnFletcherResidence("Flynn-Fletcher Residence", "The family home of Phineas, Ferb, and Candace. It's a cozy place with rooms full of secrets, and Candace is often lurking around, hoping to catch her brothers in the act."),
      doofenshmirtzEvilInc("Doofenshmirtz Evil Incorporated", "The towering lair of Dr. Doofenshmirtz. It's filled with quirky, dangerous inventions and a hint of chaos, with Doofenshmirtz always working on his next big scheme."),
      constructionSite("Construction Site", "A dusty, active construction zone where hard hats and heavy machinery are everywhere. This is where big projects take shape under the watchful eye of the construction worker."),
      baljeetHouse("Baljeet's House", "The home of Baljeet, a science-loving genius. His room is filled with books, gadgets, and the occasional experimental project - a treasure trove for any budding inventor."),
      bufordHouse("Buford's House", "Buford's home is a mix of toughness and sentimental value, with sports memorabilia, odd finds, and, of course, his cherished peanut butter stash."),
      danvillePark("Danville Park", "A lively public park where friends gather, games are played, and adventures await. It's a great place to find hints and extra items while enjoying the outdoors."),
      secretLair("Secret Lair", "Perry's hidden headquarters filled with high-tech tools and gadgets. Carl is here, providing mission briefings and helpful information about Perry's next steps."),

      phineas("Phineas", "An imaginative and enthusiastic inventor, always excited to bring his big ideas to life. Phineas is the mastermind behind the roller coaster project, always ready to give direction and guidance."),
      candace("Candace", "The determined older sister of Phineas and Ferb. She's always on a mission to bust her brothers' wild schemes but can't help being curious about what they're up to this time."),
      constructionWorker("Construction Worker", "A no-nonsense builder who works tirelessly at the construction site. He's skilled with tools and has valuable knowledge about putting large projects together."),
      drDoofenshmirtz("Dr. Doofenshmirtz", "An eccentric evil scientist with a knack for bizarre inventions. Despite his schemes, Doofenshmirtz is more humorous than harmful and might even share a few odd items if approached."),
      majorMonogram("Major Monogram", "A stern but supportive commander of Perry's missions. Major Monogram provides mission updates and guidance, ensuring everyone's prepared for the task at hand."),
        
      blowtorch("Blowtorch", "A heavy-duty blowtorch with a bright orange flame, perfect for metalwork and essential for the roller coaster's construction.", 1),
      peanutButter("Peanut Butter", "A jar of Buford's favorite chunky peanut butter. Surprisingly helpful in assembling machinery, as Phineas has discovered.", 1),
      wrench("Wrench", "A sturdy, well-used wrench that's just the right size for tightening bolts on a big project.", 1),
      roboMachine("Robo Machine", "A robotic assembly tool with multiple appendages and a friendly beep. Essential for assembling complex parts of the roller coaster.", 30),
      computerChip("Computer Chip", "A tiny but powerful computer chip that controls key functions of the roller coaster, packed with high-tech circuitry.", 1),
      blueprints("Blueprints", "Detailed blueprints with every line and measurement needed to bring Phineas and Ferb's roller coaster vision to life.", 1)
{
    create_world();
}

// Main Game Loop
void Game::play() {
    std::cout << "Starting the Phineas and Ferb Adventure Game...\n";
    std::cout << "Collect all the necessary parts to build the roller coaster and give them to Phineas in the Backyard Workshop to win the game!\n";
    // Set up commands
    commands = setup_commands();

    current_location->set_visited();

    // Main game loop
    while (game_in_progress) {
        std::cout << "==============================================================================\n";
        std::cout << "Enter a command (type 'help' for a list of valid commands): ";

        // Get user input
        std::string user_input;
        std::getline(std::cin, user_input);

        // Split user input into command and target
        std::istringstream iss(user_input);
        std::vector<std::string> tokens;
        std::string token;
        while (iss >> token) {
            tokens.push_back(token);
        }

        if (tokens.empty()) {
            std::cout << "Please enter a command.\n";
            continue;
        }

        // Extract the command
        std::string command = tokens[0];
        tokens.erase(tokens.begin());

        // Join the remaining tokens to form the full target
        std::string target;
        for (const auto& word : tokens) {
            if (!target.empty()) {
                target += " ";
            }
            target += word;
        }

        // Check if the command exists in the map
        if (commands.find(command) != commands.end()) {
            // Call the corresponding function with the full target as a single-element vector
            commands[command]({target});
        } else {
            std::cout << "Unknown command. Type 'help' for a list of commands.\n";
        }
    }

 }

// Create the World
void Game::create_world() {
    gameInstance = this; // Set the global game instance
    std::signal(SIGINT, handle_signal); // Register the signal handler

    // Add NPCs to Locations
    flynnFletcherResidence.add_npc(candace);
    backyardWorkshop.add_npc(phineas);
    doofenshmirtzEvilInc.add_npc(drDoofenshmirtz);
    constructionSite.add_npc(constructionWorker);
    secretLair.add_npc(majorMonogram);

    // Add Items to Locations
    doofenshmirtzEvilInc.add_item(blowtorch);
    bufordHouse.add_item(peanutButter);
    flynnFletcherResidence.add_item(wrench);
    constructionSite.add_item(roboMachine);
    secretLair.add_item(computerChip);
    baljeetHouse.add_item(blueprints);

    // Set up Neighbors (Link Locations)
    flynnFletcherResidence.add_location("North", &backyardWorkshop);
    flynnFletcherResidence.add_location("South", &danvillePark);
    flynnFletcherResidence.add_location("West", &baljeetHouse);
    flynnFletcherResidence.add_location("East", &constructionSite);

    backyardWorkshop.add_location("North", &secretLair);
    backyardWorkshop.add_location("South", &flynnFletcherResidence);

    secretLair.add_location("South", &backyardWorkshop);

    danvillePark.add_location("North", &flynnFletcherResidence);

    baljeetHouse.add_location("West", &bufordHouse);
    baljeetHouse.add_location("East", &flynnFletcherResidence);

    bufordHouse.add_location("East", &baljeetHouse);

    constructionSite.add_location("West", &flynnFletcherResidence);
    constructionSite.add_location("East", &doofenshmirtzEvilInc);

    doofenshmirtzEvilInc.add_location("West", &constructionSite);

    // Store Locations in Vector
    locations.push_back(flynnFletcherResidence);
    locations.push_back(backyardWorkshop);
    locations.push_back(doofenshmirtzEvilInc);
    locations.push_back(constructionSite);
    locations.push_back(baljeetHouse);
    locations.push_back(bufordHouse);
    locations.push_back(danvillePark);
    locations.push_back(secretLair);

    // Set Starting Location
    current_location = &flynnFletcherResidence;

    // Initialize audio files for each NPC
    candace.add_audio_file("In Charge", "./audio/npcs/candace/candace1-in-charge.wav");
    candace.add_audio_file("Can't Wait", "./audio/npcs/candace/candace2-cant-wait.wav");
    candace.add_audio_file("Roller Coaster", "./audio/npcs/candace/candace3-roller-coaster.wav");
    candace.add_audio_file("Down Down Down", "./audio/npcs/candace/candace4-down-down-down.wav");
    candace.add_audio_file("Telling Mom", "./audio/npcs/candace/candace5-telling-mom.wav");

    candace.init();

    constructionWorker.add_audio_file("A Little Young", "./audio/npcs/construction-worker/construction1-a-little-young.wav");
    constructionWorker.add_audio_file("Crayon Forms", "./audio/npcs/construction-worker/construction2-crayon-forms.wav");

    constructionWorker.init();

    drDoofenshmirtz.add_audio_file("Unexpected Surprise", "./audio/npcs/doofenshmirtz/doof1-unexpected-surprise.wav");
    drDoofenshmirtz.add_audio_file("Evil Plan", "./audio/npcs/doofenshmirtz/doof2-evil-plan.wav");
    drDoofenshmirtz.add_audio_file("Pizza Delivery Guy", "./audio/npcs/doofenshmirtz/doof3-pizza-delivery-guy.wav");
    drDoofenshmirtz.add_audio_file("Getting Warmer", "./audio/npcs/doofenshmirtz/doof4-getting-warmer.wav");
    drDoofenshmirtz.add_audio_file("Red Button", "./audio/npcs/doofenshmirtz/doof5-red-button.wav");

    drDoofenshmirtz.init();

    majorMonogram.add_audio_file("Tinfoil", "./audio/npcs/monogram/monogram1-tinfoil.wav");
    majorMonogram.add_audio_file("Stop to It", "./audio/npcs/monogram/monogram2-stop-to-it.wav");
    majorMonogram.add_audio_file("Cover", "./audio/npcs/monogram/monogram3-cover.wav");
    majorMonogram.add_audio_file("Counting on You", "./audio/npcs/monogram/monogram4-counting-on-you.wav");
    majorMonogram.add_audio_file("Good Luck", "./audio/npcs/monogram/monogram5-good-luck.wav");

    majorMonogram.init();

    // Initialize audio files for Phineas
    phineas.add_audio_file("Blowtorch Prompt", "./audio/npcs/phineas/phineas1-blowtorch/blowtorch-prompt.wav");
    phineas.add_audio_file("Blowtorch Correct", "./audio/npcs/phineas/phineas1-blowtorch/blowtorch-correct.wav");
    phineas.add_audio_file("Blowtorch Incorrect", "./audio/npcs/phineas/phineas1-blowtorch/blowtorch-incorrect.wav");
    phineas.add_audio_file("Blowtorch Waiting", "./audio/npcs/phineas/phineas1-blowtorch/blowtorch-waiting.wav");

    phineas.add_audio_file("Peanut Butter Prompt", "./audio/npcs/phineas/phineas2-peanut-butter/peanut-butter-prompt.wav");
    phineas.add_audio_file("Peanut Butter Correct", "./audio/npcs/phineas/phineas2-peanut-butter/peanut-butter-correct.wav");
    phineas.add_audio_file("Peanut Butter Incorrect", "./audio/npcs/phineas/phineas2-peanut-butter/peanut-butter-incorrect.wav");
    phineas.add_audio_file("Peanut Butter Waiting", "./audio/npcs/phineas/phineas2-peanut-butter/peanut-butter-waiting.wav");

    phineas.add_audio_file("Wrench Prompt", "./audio/npcs/phineas/phineas3-wrench/wrench-prompt.wav");
    phineas.add_audio_file("Wrench Correct", "./audio/npcs/phineas/phineas3-wrench/wrench-correct.wav");
    phineas.add_audio_file("Wrench Incorrect", "./audio/npcs/phineas/phineas3-wrench/wrench-incorrect.wav");
    phineas.add_audio_file("Wrench Waiting", "./audio/npcs/phineas/phineas3-wrench/wrench-waiting.wav");

    phineas.add_audio_file("Robo Machine Prompt", "./audio/npcs/phineas/phineas4-robo-machine/robo-machine-prompt.wav");
    phineas.add_audio_file("Robo Machine Correct", "./audio/npcs/phineas/phineas4-robo-machine/robo-machine-correct.wav");
    phineas.add_audio_file("Robo Machine Incorrect", "./audio/npcs/phineas/phineas4-robo-machine/robo-machine-incorrect.wav");
    phineas.add_audio_file("Robo Machine Waiting", "./audio/npcs/phineas/phineas4-robo-machine/robo-machine-waiting.wav");

    phineas.add_audio_file("Computer Chip Prompt", "./audio/npcs/phineas/phineas5-computer-chip/computer-chip-prompt.wav");
    phineas.add_audio_file("Computer Chip Correct", "./audio/npcs/phineas/phineas5-computer-chip/computer-chip-correct.wav");
    phineas.add_audio_file("Computer Chip Incorrect", "./audio/npcs/phineas/phineas5-computer-chip/computer-chip-incorrect.wav");
    phineas.add_audio_file("Computer Chip Waiting", "./audio/npcs/phineas/phineas5-computer-chip/computer-chip-waiting.wav");

    phineas.add_audio_file("Blueprints Prompt", "./audio/npcs/phineas/phineas6-blueprints/blueprints-prompt.wav");
    phineas.add_audio_file("Blueprints Correct", "./audio/npcs/phineas/phineas6-blueprints/blueprints-correct.wav");
    phineas.add_audio_file("Blueprints Incorrect", "./audio/npcs/phineas/phineas6-blueprints/blueprints-incorrect.wav");
    phineas.add_audio_file("Blueprints Waiting", "./audio/npcs/phineas/phineas6-blueprints/blueprints-waiting.wav");

    phineas.add_audio_file("Roller Coaster Start", "./audio/unused/x-phineas/roller-coaster-start.wav");

    phineas.init();

    current_location->set_visited();
}

void Game::go(std::vector<std::string> target) {
    // Check if a direction was provided
    if (target.empty()) {
        std::cout << "You need to specify a direction (e.g., 'go North').\n";
        return;
    }

    // Check if the player is carrying too much weight
    if (weight > 30) {
        std::cout << "You are carrying too much weight and cannot move. Try dropping some items.\n";
        return;
    }

    // Get the direction from the user input (first word in target vector)
    std::string direction = target[0];

    // Check if the direction exists in the current location's neighbors
    auto neighbors = current_location->get_locations();
    if (neighbors.find(direction) != neighbors.end()) {
        // Move to the new location
        current_location = neighbors[direction];
        // Mark the new location as visited
        current_location->set_visited();

        // Print the new location's name and description
        std::cout << "You go " << direction << " and arrive at " << current_location->get_name() << ".\n";
        std::cout << current_location->get_description() << "\n";
    } else {
        // Direction is not valid
        std::cout << "You can't go that way. Try a different direction.\n";
    }
}

void Game::look(std::vector<std::string> target) {
    if (!current_location) {
        std::cout << "Error: Current location is undefined.\n";
        return;
    }

    // Print the details of the current location
    std::cout << *current_location << "\n";
}

void Game::take(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Please specify an item to take.\n";
        return;
    }

    std::string item_name = target[0];

    // Get the list of items in the current location.
    auto& items_in_location = current_location->get_items();

    // Find the item in the current location's inventory using its name.
    auto item_iterator = std::find_if(items_in_location.begin(), items_in_location.end(),
                                      [&](const std::reference_wrapper<Item>& item) {
                                          return item.get().get_name() == item_name;
                                      });

    // Check if the item was found.
    if (item_iterator == items_in_location.end()) {
        std::cout << "The item '" << item_name << "' is not in this location.\n";
        return;
    }

    // Get the reference to the found item.
    Item& found_item = item_iterator->get();
    int item_weight = found_item.get_weight();

    // Add the item to the player's inventory and update the carried weight.
    inventory.push_back(found_item);
    weight += item_weight;

    // Remove the item from the current location's inventory.
    current_location->remove_item(item_name);

    std::cout << "You have taken the '" << found_item.get_name() << "' (Weight: " << item_weight << ").\n";
}

void Game::drop(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Please specify an item to drop.\n";
        return;
    }

    // Join the target words to form the full item name (e.g., "Robo Machine").
    std::string item_name;
    for (const auto& word : target) {
        if (!item_name.empty()) {
            item_name += " ";
        }
        item_name += word;
    }

    // Find the item in the player's inventory using its full name.
    auto item_iterator = std::find_if(inventory.begin(), inventory.end(),
                                      [&](Item& item) {
                                          return item.get_name() == item_name;
                                      });

    // Check if the item was found in the inventory.
    if (item_iterator == inventory.end()) {
        std::cout << "You do not have the item '" << item_name << "' in your inventory.\n";
        return;
    }

    // Get a reference to the found item (do not make a copy).
    Item& dropped_item = *item_iterator;

    // Add the item back to the current location's inventory using a reference wrapper.
    current_location->add_item(std::ref(dropped_item));
    //std::cout << "Debug - Dropped item: " << dropped_item.get_name() << " (Weight: " << dropped_item.get_weight() << ")\n";

    // Remove the item from the player's inventory and update the carried weight.
    int item_weight = dropped_item.get_weight();
    inventory.erase(item_iterator);
    weight -= item_weight;

    std::cout << "You have dropped the '" << dropped_item.get_name() << "' (Weight: " << item_weight << ").\n";
}


void Game::show_inventory(std::vector<std::string> target) {
    if (inventory.empty()) {
        std::cout << "Your inventory is empty.\n";
        return;
    }

    std::cout << "Your inventory contains:\n";
    for (const auto& item : inventory) {
        std::cout << " - " << item.get_name() << " (Weight: " << item.get_weight() << ")\n";
    }

    std::cout << "Total weight carried: " << weight << "\n";
}

void Game::meet(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Please specify an NPC to meet.\n";
        return;
    }

    std::string npc_name = target[0];

    // Check if the current location has any NPCs.
    const auto& npcs_in_location = current_location->get_npcs();
    if (npcs_in_location.empty()) {
        std::cout << "There are no NPCs in this location.\n";
        return;
    }

    // Find the NPC in the current location using reference wrapper correctly.
    auto npc_it = std::find_if(npcs_in_location.begin(), npcs_in_location.end(),
                               [&](const std::reference_wrapper<NPC>& npc_ref) {
                                   return npc_ref.get().get_name() == npc_name;
                               });

    // Check if the NPC was found.
    if (npc_it == npcs_in_location.end()) {
        std::cout << "The NPC '" << npc_name << "' is not in this location.\n";
        return;
    }

    // Safely access the NPC using reference wrapper.
    NPC& found_npc = npc_it->get();

    // Print the NPC's description.
    std::string description = found_npc.get_description();
    std::cout << "You meet " << npc_name << ". " << description << "\n";
}

void Game::talk(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Please specify an NPC to talk to.\n";
        return;
    }

    std::string npc_name = target[0];

    // Check if the current location has any NPCs
    const auto& npcs_in_location = current_location->get_npcs();
    if (npcs_in_location.empty()) {
        std::cout << "There are no NPCs in this location.\n";
        return;
    }

    // Find the NPC in the current location
    auto npc_it = std::find_if(npcs_in_location.begin(), npcs_in_location.end(),
                               [&](const std::reference_wrapper<NPC>& npc_ref) {
                                   return npc_ref.get().get_name() == npc_name;
                               });

    if (npc_it == npcs_in_location.end()) {
        std::cout << "The NPC '" << npc_name << "' is not in this location.\n";
        return;
    }

    // Safely access the NPC
    NPC& found_npc = npc_it->get();

    // Special handling for Phineas
    if (npc_name == "Phineas") {
        // Provide the prompt based on the current level
        switch (level) {
            case 1:
                std::cout << "Hey, could you grab the blowtorch? It's the one with the bright orange flame! We'll need it for some heavy-duty metalwork.\n";
                found_npc.play_audio("Blowtorch Prompt");
                break;
            case 2:
                std::cout << "Next, we're going to need Buford's chunky peanut butter. Don't ask why—it just works!\n";
                found_npc.play_audio("Peanut Butter Prompt");
                break;
            case 3:
                std::cout << "Now, I could use a wrench. It's the one that's just the right size for some big bolts!\n";
                found_npc.play_audio("Wrench Prompt");
                break;
            case 4:
                std::cout << "Could you find the Robo Machine? It's got all sorts of gadgets and a friendly little beep.\n";
                found_npc.play_audio("Robo Machine Prompt");
                break;
            case 5:
                std::cout << "Next up, I'll need a computer chip. It's small but super powerful—key to controlling the roller coaster.\n";
                found_npc.play_audio("Computer Chip Prompt");
                break;
            case 6:
                std::cout << "Finally, could you bring over the blueprints? They have all our measurements and designs!\n";
                found_npc.play_audio("Blueprints Prompt");
                break;
            default:
                std::cout << "We have everything we need! Let's build the roller coaster!\n";
                break;
        }
    } else {
        // For all other NPCs, play the next audio in their sequence
        found_npc.play_next();
    }
}



void Game::quit(std::vector<std::string> target) {
    game_in_progress = false;
    phineas.cleanup();
    candace.cleanup();
    drDoofenshmirtz.cleanup();
    majorMonogram.cleanup();
    constructionWorker.cleanup();
    std::cout << "Quitting the game.\n";
}


void Game::give(std::vector<std::string> target) {
    if (target.empty()) {
        std::cout << "Please specify an item to give.\n";
        return;
    }

    // Check if the player is at the Backyard Workshop
    if (current_location->get_name() != "Backyard Workshop") {
        std::cout << "You can only give items to Phineas at the Backyard Workshop.\n";
        return;
    }

    std::string item_name = target[0];

    // Check if the item matches the expected item for the current level
    if (item_name != required_items[level - 1]) {
        switch (level) {
            case 1:
                std::cout << "Hmm, that's not quite it. I need the blowtorch to get started!\n";
                phineas.play_audio("Blowtorch Incorrect");
                break;
            case 2:
                std::cout << "Close, but no peanut butter! Could you bring that over?\n";
                phineas.play_audio("Peanut Butter Incorrect");
                break;
            case 3:
                std::cout << "That's not quite right. I still need the wrench to get things tightened down.\n";
                phineas.play_audio("Wrench Incorrect");
                break;
            case 4:
                std::cout << "Hmm, that's not the Robo Machine. Try again—it's got to be around here somewhere.\n";
                phineas.play_audio("Robo Machine Incorrect");
                break;
            case 5:
                std::cout << "Not quite. I need the computer chip for the controls. Could you look again?\n";
                phineas.play_audio("Computer Chip Incorrect");
                break;
            case 6:
                std::cout << "That's not the blueprints. I still need them to get everything in order.\n";
                phineas.play_audio("Blueprints Incorrect");
                break;
        }
        return;
    }

    // Find the item in the player's inventory
    auto item_iterator = std::find_if(inventory.begin(), inventory.end(),
                                      [&](const Item& item) {
                                          return item.get_name() == item_name;
                                      });

    if (item_iterator == inventory.end()) {
        std::cout << "You don't have the " << item_name << " in your inventory.\n";
        return;
    }

    // Remove the item from the inventory and update weight
    int item_weight = item_iterator->get_weight();
    inventory.erase(item_iterator);
    weight -= item_weight;

    // Print the correct message and play audio based on the current level
    switch (level) {
        case 1:
            std::cout << "Awesome! This blowtorch is exactly what we need. Thanks a bunch!\n";
            phineas.play_audio("Blowtorch Correct");
            break;
        case 2:
            std::cout << "Perfect! Peanut butter is always the secret ingredient. Thanks for grabbing it!\n";
            phineas.play_audio("Peanut Butter Correct");
            break;
        case 3:
            std::cout << "You got it! This wrench is exactly what we need to tighten things up.\n";
            phineas.play_audio("Wrench Correct");
            break;
        case 4:
            std::cout << "Yes! The Robo Machine is here and ready to assemble. Thanks for finding it!\n";
            phineas.play_audio("Robo Machine Correct");
            break;
        case 5:
            std::cout << "Perfect! This computer chip is just what we need. Thanks!\n";
            phineas.play_audio("Computer Chip Correct");
            break;
        case 6:
            std::cout << "Awesome! Now we have everything we need to bring this roller coaster to life!\n";
            phineas.play_audio("Blueprints Correct");
            break;
    }

    // Increment the level
    level++;

    // Check if the player has completed the game
    if (level > 6) {
        phineas.play_audio("Roller Coaster Start"); // Optional finale audio
        std::cout << "Congratulations! You've given all the items to Phineas. The roller coaster is complete! You win the game!\n";
        game_in_progress = false;
    }
}




void Game::show_help() {
    std::cout << "Available Commands:\n";
    std::cout << " - look: Look around the current location\n";
    std::cout << " - go <direction>: Move to a new location\n";
    std::cout << " - take <item>: Take an item from the current location\n";
    std::cout << " - drop <item>: Give an item from your inventory\n";
    std::cout << " - inventory: List of items in your inventory\n";
    std::cout << " - meet <NPC Name>: Get the description of a NPC\n";
    std::cout << " - talk <NPC Name>: Talk to an NPC\n";
    std::cout << " - give <item>: Given item to Phineas to help build the rollar coaster\n";
    std::cout << " - help: Show this help message\n";
    std::cout << " - quit: Exit the game\n";
    current_location->set_visited();
}

std::map<std::string, std::function<void(std::vector<std::string>)>> Game::setup_commands() {
    std::map<std::string, std::function<void(std::vector<std::string>)>> commands;

    // Adding full commands
    commands["help"] = [this](std::vector<std::string> args) { this->show_help(); }; 
    commands["go"] = [this](std::vector<std::string> args) { this->go(args); }; 
    commands["look"] = [this](std::vector<std::string> args) { this->look(args); };
    commands["take"] = [this](std::vector<std::string> args) { this->take(args); };
    commands["drop"] = [this](std::vector<std::string> args) { this->drop(args); };
    commands["inventory"] = [this](std::vector<std::string> args) { this->show_inventory(args); };
    commands["quit"] = [this](std::vector<std::string> args) { this->quit(args); };
    commands["meet"] = [this](std::vector<std::string> args) { this->meet(args); };
    commands["talk"] = [this](std::vector<std::string> args) { this->talk(args); };
    commands["give"] = [this](std::vector<std::string> args) { this->give(args); };

    // Aliases
    commands["h"] = commands["help"];
    commands["?"] = commands["help"];

    commands["g"] = commands["go"];
    commands["cd"] = commands["go"];

    commands["l"] = commands["look"];
    commands["ls"] = commands["look"];

    commands["c"] = commands["take"];
    commands["collect"] = commands["take"];
    commands["grab"] = commands["take"];

    commands["d"] = commands["drop"];
    commands["discard"] = commands["drop"];

    commands["i"] = commands["inventory"];

    commands["q"] = commands["quit"];
    commands["exit"] = commands["quit"];
    commands["x"] = commands["quit"];


    commands["m"] = commands["meet"];
    commands["o"] = commands["observe"];

    commands["t"] = commands["talk"];
    commands["v"] = commands["give"]; // Using 'v' for 'give' to avoid conflicts

    return commands;
}
