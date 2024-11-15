#include "Game.h"
#include <iostream>

// Constructor
Game::Game()
    : backyardWorkshop("Backyard Workshop", "The creative hub where Phineas and Ferb bring their wild ideas to life. It’s filled with tools, gadgets, and half-finished projects – the perfect place for big inventions."),
      flynnFletcherResidence("Flynn-Fletcher Residence", "The family home of Phineas, Ferb, and Candace. It’s a cozy place with rooms full of secrets, and Candace is often lurking around, hoping to catch her brothers in the act."),
      doofenshmirtzEvilInc("Doofenshmirtz Evil Incorporated", "The towering lair of Dr. Doofenshmirtz. It’s filled with quirky, dangerous inventions and a hint of chaos, with Doofenshmirtz always working on his next big scheme."),
      constructionSite("Construction Site", "A dusty, active construction zone where hard hats and heavy machinery are everywhere. This is where big projects take shape under the watchful eye of the construction worker."),
      baljeetHouse("Baljeet's House", "The home of Baljeet, a science-loving genius. His room is filled with books, gadgets, and the occasional experimental project – a treasure trove for any budding inventor."),
      bufordHouse("Buford's House", "Buford’s home is a mix of toughness and sentimental value, with sports memorabilia, odd finds, and, of course, his cherished peanut butter stash."),
      danvillePark("Danville Park", "A lively public park where friends gather, games are played, and adventures await. It’s a great place to find hints and extra items while enjoying the outdoors."),
      secretLair("Secret Lair", "Perry’s hidden headquarters filled with high-tech tools and gadgets. Carl is here, providing mission briefings and helpful information about Perry’s next steps."),

      phineas("Phineas", "An imaginative and enthusiastic inventor, always excited to bring his big ideas to life. Phineas is the mastermind behind the roller coaster project, always ready to give direction and guidance."),
      candace("Candace", "The determined older sister of Phineas and Ferb. She’s always on a mission to bust her brothers’ wild schemes but can’t help being curious about what they’re up to this time."),
      constructionWorker("Construction Worker", "A no-nonsense builder who works tirelessly at the construction site. He’s skilled with tools and has valuable knowledge about putting large projects together."),
      drDoofenshmirtz("Dr. Doofenshmirtz", "An eccentric evil scientist with a knack for bizarre inventions. Despite his schemes, Doofenshmirtz is more humorous than harmful and might even share a few odd items if approached."),
      majorMonogram("Major Monogram", "A stern but supportive commander of Perry’s missions. Major Monogram provides mission updates and guidance, ensuring everyone’s prepared for the task at hand."),
        
      blowtorch("Blowtorch", "A heavy-duty blowtorch with a bright orange flame, perfect for metalwork and essential for the roller coaster's construction.", 1),
      peanutButter("Peanut Butter", "A jar of Buford’s favorite chunky peanut butter. Surprisingly helpful in assembling machinery, as Phineas has discovered.", 1),
      wrench("Wrench", "A sturdy, well-used wrench that’s just the right size for tightening bolts on a big project.", 1),
      roboMachine("Robo Machine", "A robotic assembly tool with multiple appendages and a friendly beep. Essential for assembling complex parts of the roller coaster.", 1),
      computerChip("Computer Chip", "A tiny but powerful computer chip that controls key functions of the roller coaster, packed with high-tech circuitry.", 1),
      blueprints("Blueprints", "Detailed blueprints with every line and measurement needed to bring Phineas and Ferb’s roller coaster vision to life.", 1)
{
    create_world();
}

// Main Game Loop
void Game::play() {
    std::cout << "Starting the Phineas and Ferb Adventure Game...\n";
    std::cout << "Current Location: " << *current_location << "\n";

    // Print all locations
    std::cout << "\nListing all locations:\n";
    for (const auto& location : locations) {
        std::cout << location << "\n";
    }

    // Test playing audio for each NPC
    test_play_audio();
}

void Game::test_play_audio() {
    std::cout << "\nTesting audio playback for each NPC:\n";

    // Play audio for Candace
    candace.play_audio("In Charge");
    std::cout << "Press Enter to stop and play the next sound...";
    std::cin.get();

    // Continue with other NPCs
    constructionWorker.play_audio("A Little Young");
    std::cout << "Press Enter to stop and play the next sound...";
    std::cin.get();
}

// Create the World
void Game::create_world() {
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
    flynnFletcherResidence.add_location("Backyard Workshop", &backyardWorkshop);
    backyardWorkshop.add_location("Flynn-Fletcher Residence", &flynnFletcherResidence);
    backyardWorkshop.add_location("Secret Lair", &secretLair);
    bufordHouse.add_location("Danville Park", &danvillePark);
    baljeetHouse.add_location("Danville Park", &danvillePark);
    constructionSite.add_location("Danville Park", &danvillePark);
    danvillePark.add_location("Baljeet's House", &baljeetHouse);
    danvillePark.add_location("Buford's House", &bufordHouse);
    danvillePark.add_location("Construction Site", &constructionSite);
    danvillePark.add_location("Doofenshmirtz Evil Incorporated", &doofenshmirtzEvilInc);
    doofenshmirtzEvilInc.add_location("Danville Park", &danvillePark);
    secretLair.add_location("Backyard Workshop", &backyardWorkshop);

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
    candace.add_audio_file("In Charge", "../audio/npcs/candace/candace1-in-charge.wav");
    candace.add_audio_file("Can't Wait", "../audio/npcs/candace/candace2-cant-wait.wav");
    candace.add_audio_file("Roller Coaster", "../audio/npcs/candace/candace3-roller-coaster.wav");
    candace.add_audio_file("Down Down Down", "../audio/npcs/candace/candace4-down-down-down.wav");
    candace.add_audio_file("Telling Mom", "../audio/npcs/candace/candace5-telling-mom.wav");

    constructionWorker.add_audio_file("A Little Young", "../audio/npcs/construction-worker/construction1-a-little-young.wav");
    constructionWorker.add_audio_file("Crayon Forms", "../audio/npcs/construction-worker/construction2-crayon-forms.wav");

    drDoofenshmirtz.add_audio_file("Unexpected Surprise", "../audio/npcs/doofenshmirtz/doof1-unexpected-surprise.wav");
    drDoofenshmirtz.add_audio_file("Evil Plan", "../audio/npcs/doofenshmirtz/doof2-evil-plan.wav");
    drDoofenshmirtz.add_audio_file("Pizza Delivery Guy", "../audio/npcs/doofenshmirtz/doof3-pizza-delivery-guy.wav");
    drDoofenshmirtz.add_audio_file("Getting Warmer", "../audio/npcs/doofenshmirtz/doof4-getting-warmer.wav");
    drDoofenshmirtz.add_audio_file("Red Button", "../audio/npcs/doofenshmirtz/doof5-red-button.wav");

    majorMonogram.add_audio_file("Tinfoil", "../audio/npcs/monogram/monogram1-tinfoil.wav");
    majorMonogram.add_audio_file("Stop to It", "../audio/npcs/monogram/monogram2-stop-to-it.wav");
    majorMonogram.add_audio_file("Cover", "../audio/npcs/monogram/monogram3-cover.wav");
    majorMonogram.add_audio_file("Counting on You", "../audio/npcs/monogram/monogram4-counting-on-you.wav");
    majorMonogram.add_audio_file("Good Luck", "../audio/npcs/monogram/monogram5-good-luck.wav");
}

