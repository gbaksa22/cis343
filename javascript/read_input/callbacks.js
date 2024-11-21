const readline = require('readline');

// Function to create a readline interface
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

rl.question("What is your name? ", name => { 
	console.log("Hello, " + name); 
	rl.question("How are you feeling? ", mood => {
		console.log("You are feeling " + mood);
		rl.close();
	})
})