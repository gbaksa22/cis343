const readline = require('readline');

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// Callback function that waits for user input before running console.log
rl.question("What is your name? ", name => {
    console.log(`Hello, ${name}!`);
    rl.question("Watcha doin? ", doing => {
        console.log("You're doing " + doing);
        rl.close();
    });
});