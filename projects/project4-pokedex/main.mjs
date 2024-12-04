import { searchPoke, searchItem, searchMove } from './fetch.mjs';
import { printPoke, printItem, printMove, showMenu } from './display.mjs';

// Prompt the user for input and pass it to a callback function
function prompt(cb) {
    // Use readline to get input from the user
    // Pass the entered term to the provided callback function
}

// Main function to run the application
function run() {
    // Call showMenu() to display options
    // Use readline to get the user's choice
    // Call prompt with the appropriate search function based on the choice
    searchPoke('pikachu');
    searchItem('oran-berry');

}

// Start the application
run();
