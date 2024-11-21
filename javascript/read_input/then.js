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

// Using .then with resolve and reject
askQuestion("What's your favorite programming language? ")
  .then((answer) => {
    console.log(`You said: ${answer}`);
  })
  .catch((error) => {
    console.error('Error:', error.message);
  });