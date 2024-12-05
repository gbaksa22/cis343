import { searchPoke, searchItem, searchMove } from './fetch.mjs';
import { printPoke, printItem, printMove, showMenu } from './display.mjs';
import readline from 'readline';

const rl = readline.createInterface({input: process.stdin, output: process.stdout});

// Prompt the user for input and pass it to a callback function
function prompt(cb) {
    // Use readline to get input from the user
    // Pass the entered term to the provided callback function
    rl.question("Enter a search term: ", (term) => {
        cb(term);
    });
}

// Main function to run the application
export function run() {
    // Call showMenu() to display options
    // Use readline to get the user's choice
    // Call prompt with the appropriate search function based on the choice
    
    // Display the menu options
    showMenu();

    // Ask the user for their choice
    rl.question("Choose an option: ", (choice) => {
        switch (choice) {
            case "1":
                console.log("Searching for a Pokemon by name");
                // Pass searchPoke as the callback
                prompt(searchPoke); 
                break;
            case "2":
                console.log("Searching for an Item by name");
                // Pass searchItem as the callback
                prompt(searchItem); 
                break;
            case "3":
                console.log("Searching for a Move by name");
                // Pass searchMove as the callback
                prompt(searchMove); 
                break;
            case "4":
                console.log("Exiting");
                // Close the readline
                rl.close(); 
                break;
            default:
                console.log("Invalid choice. Please try again.");
                run();
                break;
        }
    });
    //searchPoke('pikachu');
    //searchItem('oran-berry');
    //searchMove('thunder-punch');
}

// Start the application
run();

