const readline = require('readline');

// Function to ask a question using readline with Promise
function askQuestion(query) {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  return new Promise((resolve, reject) => {
    rl.question(query, (answer) => {
      rl.close();

      if (answer.trim() === '') {
        reject(new Error('Input cannot be empty!'));
      } else {
        resolve(answer);
      }
    });

    // Optional: Handle readline errors
    rl.on('error', (err) => {
      reject(err);
    });
  });
}

// Generate a random number between min and max
function getRandomInt(min, max) {
  min = Math.ceil(min);
  max = Math.floor(max);
  return Math.floor(Math.random() * (max - min + 1)) + min;
}

// Start the number guessing game
function guessTheNumber(randomNumber) {
  askQuestion('Guess a number between 1 and 100: ')
    .then((guess) => {
      const userGuess = parseInt(guess, 10);

      if (isNaN(userGuess)) {
        console.log('That is not a valid number. Try again.');
        return guessTheNumber(randomNumber); // Retry
      }

      if (userGuess === randomNumber) {
        console.log('Congratulations! You guessed the correct number.');
      } else if (userGuess > randomNumber) {
        console.log('Too high! Try again.');
        return guessTheNumber(randomNumber); // Retry
      } else {
        console.log('Too low! Try again.');
        return guessTheNumber(randomNumber); // Retry
      }
    })
    .catch((error) => {
      console.error('Error:', error.message);
      guessTheNumber(randomNumber); // Retry if there’s an error
    });
}

// Initialize the game
console.log('Welcome to the Number Guessing Game!');
const randomNumber = getRandomInt(1, 100);
guessTheNumber(randomNumber);
