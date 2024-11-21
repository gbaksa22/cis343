import readline from 'readline'

// Function to create a readline interface
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

try {
	const name = await askQuestion("What's your name? ")
	console.log(`Hello, ${name}!`)
	const mood = await askQuestion("How are you today? ")
	console.log(`You are feeling ${mood}.`)
} catch(err) {
    console.error("An error occurred:", err);
}