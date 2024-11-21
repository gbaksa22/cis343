const readline = require('readline');

function askQuestion(query) {
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });
    
    
    return new Promise((successFunction, failureFunction) => {
        rl.question(query, answer => {
            rl.close();
            if (answer.trim === ''){
                failureFunction("Input can't be empty.");
            } else {
                successFunction(answer);
            }
        })
    })
}

askQuestion("What's your name? ")
    .then( name => { 
        console.log(`Hello, ${name}`); 
        askQuestion("How you doing?")})
    .then( doing => {
        console.log(`You're doing ${doing}`);
    .catch() err => {
        console.log
    }
    })