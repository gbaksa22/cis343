// Display Pokemon data neatly
export function printPoke(json) {
    // Format and print the Pokemon data (name, weight, height, base experience, moves)
    // Function to display Pokémon data
    console.log("==== Pokemon Data ====");
    console.log(`Name: ${json.name}`);
    console.log(`Weight: ${json.weight}`);
    console.log(`Height: ${json.height}`);
    console.log(`Base Experience: ${json.base_experience}`);
    console.log(`Moves:`);
    
    // Prints the name of each move
    for (let move of json.moves) {
        console.log(`- ${move.move.name}`);
    }

    console.log("======================\n");
}

// Display item data neatly
// An item is an object in the games that the player can pick up, store in their bag, and use in various ways.
// Items serve different purposes like healing, powering up Pokémon, catching Pokémon, or unlocking new areas.
// Reference: https://pokeapi.co/docs/v2#items-section
export function printItem(json) {
    // Get the English name of the item.
    // The first time we tried to display the name, it was in a different language, 
    // so we specify the language explicitly here to ensure it's in English.
    const englishName = json.names?.find(name => name.language.name === "en");

    // Get the English effect of the item.
    // Effects describe what the item does, but they were showing weird spacing issues in the terminal.
    // To fix that, we normalize the text by replacing extra whitespace with single spaces and trimming the ends.
    const englishEffect = json.effect_entries?.find(effect => effect.language.name === "en");
    const normalizedEffect = englishEffect?.effect.replace(/\s+/g, ' ').trim();

    // Get the English category of the item.
    // Categories group items by their general purpose (like "healing" or "standard-balls").
    const englishCategory = json.category?.name;

    // Get the name of the first Pokémon (if any) that can hold this item.
    // Not all items are held by Pokémon, so we check if the array exists and grab the first Pokémon listed.
    const heldByPokemon = json.held_by_pokemon?.[0]?.pokemon?.name;

    // Start displaying the item details.
    console.log("==== Item Details ====");

    // Display the item's name.
    if (englishName) {
        console.log(`Name: ${englishName.name}`);
    } else {
        console.log("Name: Not found in English.");
    }

    // Display the item's effect.
    if (englishEffect) {
        console.log(`Effect: ${normalizedEffect}`);
    } else {
        console.log("Effect: Not found in English.");
    }

    // Display the item's category.
    if (englishCategory) {
        console.log(`Category: ${englishCategory}`);
    } else {
        console.log("Category: Not found in English.");
    }

    // Display which Pokémon (if any) can hold the item.
    if (heldByPokemon) {
        console.log(`Held By Pokemon: ${heldByPokemon}`);
    } else {
        console.log("This item is not held by any Pokemon.");
    }

    // End of item details.
    console.log("======================\n");
}

// Display move data neatly
export function printMove(json) {
    // Format and print the move data in a clean way
    console.log("===== Move Data ======");
    console.log(`Name: ${json.name}`);
    console.log(`Accuracy: ${json.accuracy}`);
    console.log(`Effect Chance: ${json.effect_chance}`);
    console.log(`PP: ${json.pp}`);
    console.log(`Priority: ${json.priority}`);
    console.log(`Power: ${json.power}`);
    console.log(`Type: ${json.type.name}`);
    console.log("======================\n");
}

// Show the menu options to the user
export function showMenu() {
    // Display available options for searching Pokemon, items, and moves
    console.log(`==== Pokedex Menu ====\n1. Search for a Pokemon\n2. Search for an Item\n3. Search for a Move\n4. Exit\n====================`);
}
