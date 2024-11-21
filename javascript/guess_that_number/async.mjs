import readline from 'readline';

function askQuestion(query) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  return new Promise((resolve) => {
    rl.question(query, (answer) => {
      rl.close();
      resolve(answer);
    });
  });
}

// Random number generator
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Main game function
async function guessTheNumber() {
  try {
    const randomNumber = getRandomInt(1, 100);
    console.log("I have picked a random number between 1 and 100. Try to guess it!");

    while (true) {
      const guess = await askQuestion("Enter your guess: ");
      const userGuess = parseInt(guess, 10);

      if (isNaN(userGuess)) {
        console.log("Please enter a valid number.");
        continue;
      }

      if (userGuess === randomNumber) {
        console.log("Congratulations! You guessed the correct number.");
        break;
      } else if (userGuess > randomNumber) {
        console.log("Too high! Try again.");
      } else {
        console.log("Too low! Try again.");
      }
    }
  } catch (err) {
    console.error("An error occurred:", err);
  }
}

// Run the game
guessTheNumber();
