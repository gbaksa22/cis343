const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Generate a random number between min and max
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Game logic using callbacks
function guessTheNumber(randomNumber) {
  rl.question("Guess a number between 1 and 100: ", (guess) => {
    const userGuess = parseInt(guess, 10);

    if (isNaN(userGuess)) {
      console.log("That's not a valid number. Try again.");
      return guessTheNumber(randomNumber); // Retry
    }

    if (userGuess === randomNumber) {
      console.log("Congratulations! You guessed the correct number.");
      rl.close();
    } else if (userGuess > randomNumber) {
      console.log("Too high! Try again.");
      guessTheNumber(randomNumber); // Retry
    } else {
      console.log("Too low! Try again.");
      guessTheNumber(randomNumber); // Retry
    }
  });
}

// Start the game
console.log("Welcome to the Number Guessing Game!");
const randomNumber = getRandomInt(1, 100);
guessTheNumber(randomNumber);
