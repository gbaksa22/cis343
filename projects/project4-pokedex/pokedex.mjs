// Function to display all menu options to the user
function showMenu() {
    // Display the available options for searching Pokemon, items, and moves
}

// Function to prompt the user for input
// Takes a callback function (cb) to process the user input
function prompt(cb) {
    // Use readline to get input from the user
    // Pass the entered term to the provided callback function
}

// Function to query the API for a specific Pokemon by term
// Calls printPoke(json) to display the results
// Reprompts the user by calling run() after displaying results
function searchPoke(term) {
    // Fetch data for the specified Pokemon from the API
    // If valid, pass the response JSON to printPoke
    // Handle invalid responses or errors gracefully
}

// Function to neatly print the details of a Pokemon
// Includes fields like name, weight, height, base experience, and moves
function printPoke(json) {
    // Format and print the Pokemon data in a clean way
}

// Function to query the API for a specific item by term
// Calls printItem(json) to display the results
// Reprompts the user by calling run() after displaying results
function searchItem(term) {
    // Fetch data for the specified item from the API
    // If valid, pass the response JSON to printItem
    // Handle invalid responses or errors gracefully
}

// Function to neatly print the details of an item
// Displays at least four fields from the item's data
function printItem(json) {
    // Format and print the item data in a clean way
}

// Function to query the API for a specific move by term
// Calls printMove(json) to display the results
// Reprompts the user by calling run() after displaying results
function searchMove(term) {
    // Fetch data for the specified move from the API
    // If valid, pass the response JSON to printMove
    // Handle invalid responses or errors gracefully
}

// Function to neatly print the details of a move
function printMove(json) {
    // Format and print the move data in a clean way
}

// Main function to run the application
// Displays the menu and handles user interaction
function run() {
    // Call showMenu() to display options
    // Use readline to get the user's choice
    // Call prompt with the appropriate search function based on the choice
}
