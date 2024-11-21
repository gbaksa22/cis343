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

try {
    const name = await askQuestion("What is your name? ");
    const mood = await askQuestion("How are you doin");
    console.log(`Hi ${name} who is doing ${mood}.`)
} catch(err) {
    console.log(err);
}