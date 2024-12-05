import fetch from 'node-fetch';
import { printPoke, printItem, printMove, showMenu } from './display.mjs';
import { run } from './main.mjs';

// Fetch Pokemon data by term
export async function searchPoke(term) {
    // Fetch data for the specified Pokemon from the API
    // If valid, pass the response JSON to printPoke
    // Handle invalid responses or errors gracefully
    try {
        const response = await fetch(`https://pokeapi.co/api/v2/pokemon/${term}`);
        
        if (!response.ok) {
            console.log(`Error: Pokemon not found`);
            run();
        }
        
        const json = await response.json();
        
        printPoke(json);
    } catch (error) {
        console.log("Failed to fetch Pokemon data");
    }
    run();
}

// Fetch item data by term
export async function searchItem(term) {
    // Fetch data for the specified item from the API
    // If valid, pass the response JSON to printItem
    // Handle invalid responses or errors gracefully
    try {
        const response = await fetch(`https://pokeapi.co/api/v2/item/${term}`);
        
        if (!response.ok) {
            console.log(`Error: Item not found`);
            run();
        }
        
        const json = await response.json();
        
        printItem(json);
    } catch (error) {
        console.log("Failed to fetch Item data");
    }
    run();
}

// Fetch move data by term
export async function searchMove(term) {
    // Fetch data for the specified move from the API
    // If valid, pass the response JSON to printMove
    // Handle invalid responses or errors gracefully
    try {
        const response = await fetch(`https://pokeapi.co/api/v2/move/${term}`);
        
        if (!response.ok) {
            console.log(`Error: Move not found`);
            run();
        }
        
        const json = await response.json();
        
        printMove(json);
    } catch (error) {
        console.log("Failed to fetch Move data");
    }
    run();
}
