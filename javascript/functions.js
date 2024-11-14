// Defining a function as a property of an object
const myComputer = {};
myComputer.startup = function(message) {
    console.log(message);
};

// Calling the function
myComputer.startup("Booting now!");  // Output: "Booting now!"

// "Normal" function syntax
function square(x) {
    return x * x;
}
console.log(square(5));  // Output: 25

// Function expression syntax
const multiply = function(a, b) {
    return a * b;
};
console.log(multiply(4, 5));  // Output: 20

// Arrow function syntax
const add = (a, b) => {
    return a + b;
};
console.log(add(3, 7));  // Output: 10

// Simplified arrow function syntax for single-line functions
const double = x => x * 2;
console.log(double(6));  // Output: 12

// Arrow function caveats

// Example of 'this' behavior
const myObject = {
    name: "MyObject",
    regularFunction: function() {
        console.log(`Regular function 'this': ${this.name}`);
    },
    arrowFunction: () => {
        console.log(`Arrow function 'this': ${this.name}`);
    }
};

// 'this' in regular function refers to the object
myObject.regularFunction();  // Output: "Regular function 'this': MyObject"

// 'this' in arrow function does not bind to the object, it's undefined here
myObject.arrowFunction();    // Output: "Arrow function 'this': undefined"

// Note: Arrow functions cannot be used as constructors

// Regular function as a constructor
function Person(name) {
    this.name = name;
}
const alice = new Person("Alice");
console.log(alice.name);  // Output: "Alice"

// Arrow function as a constructor (throws an error)
const PersonArrow = (name) => {
    this.name = name;
};
// Uncommenting the following line will cause an error:
// const bob = new PersonArrow("Bob");
