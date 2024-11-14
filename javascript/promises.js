// Basic Promise Example
function slowCode() {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            const success = Math.random() > 0.5; // Random success/failure
            if (success) {
                resolve("Operation completed successfully!");
            } else {
                reject("Operation failed.");
            }
        }, 2000); // Simulate a delay of 2 seconds
    });
}

// Using the Promise with .then and .catch
slowCode()
    .then(result => {
        console.log(result); // Output if resolved: "Operation completed successfully!"
    })
    .catch(error => {
        console.log(error); // Output if rejected: "Operation failed."
    });

// Using fetch with Promises
const jokeAPI = 'https://v2.jokeapi.dev/joke/Any?blacklistFlags=nsfw,religious,racist,sexist,explicit';

// Fetch with .then and .catch
fetch(jokeAPI)
    .then(response => {
        if (!response.ok) throw new Error("Network response was not ok.");
        return response.json();
    })
    .then(data => {
        console.log("Joke:", data.setup || data.joke);  // Prints the joke if successful
    })
    .catch(error => {
        console.error("Failed to fetch joke:", error.message);  // Prints error message if failed
    });

// Async/Await with Try/Catch for better readability
async function fetchJoke() {
    try {
        let response = await fetch(jokeAPI);
        if (!response.ok) throw new Error("Network response was not ok.");
        
        let data = await response.json();
        console.log("Async Joke:", data.setup || data.joke);  // Prints the joke if successful
    } catch (error) {
        console.error("Failed to fetch joke:", error.message);  // Prints error message if failed
    }
}

// Calling the async function
fetchJoke();

// Explanation of Promises and Async/Await:
// - A Promise is an object representing the eventual completion or failure of an asynchronous operation.
// - .then() handles successful resolution, while .catch() handles errors.
// - Async/await allows us to write asynchronous code that looks synchronous, making it more readable.
// - Try/catch in async functions handles errors in a structured way, similar to .catch() with Promises.
