// Using const: for variables that won't be reassigned
const PI = 3.14159;
const DAYS_IN_WEEK = 7;

// Note: While `const` prevents reassignment, if the variable is an object or array,
// you can still modify the contents.

const person = { name: "Alice", age: 25 };
person.age = 26;  // This is allowed as we are modifying the object, not reassigning it.

const colors = ["red", "green", "blue"];
colors.push("yellow");  // This is allowed; we are adding to the array, not reassigning it.

// Using let: for variables that may be reassigned
let score = 10;
score = 15;  // Reassignment is allowed with let

let greeting = "Hello";
if (true) {
    let greeting = "Hi";  // This greeting is scoped to the block
    console.log(greeting); // Outputs "Hi"
}

console.log(greeting);  // Outputs "Hello", showing block scoping with let
