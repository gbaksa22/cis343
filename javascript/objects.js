// Basic Object Literal
let myComputer = {
    ram: '16G',
    cores: 4
};

// Accessing properties
console.log(myComputer.ram);         // Output: "16G"
console.log(myComputer['cores']);    // Output: 4

// Adding new properties dynamically
myComputer.gpu = 'NVIDIA';
console.log(myComputer.gpu);         // Output: "NVIDIA"

// Checking if a property exists
console.log(myComputer.storage);     // Output: undefined
myComputer.storage = null;           // Setting storage to null indicates no value

// Factory Function
let createStudent = function(name, id, gpa) {
    return {
        name: name,
        id: id,
        gpa: gpa
    };
};

let student1 = createStudent("Josephine", 123456, 4.0);
console.log(student1.name);          // Output: "Josephine"

// Constructor Function with 'new'
function Student(name, id, gpa) {
    this.name = name;
    this.id = id;
    this.gpa = gpa;
}

let student2 = new Student("Alex", 654321, 3.8);
console.log(student2.gpa);           // Output: 3.8

// Using Object.create() to set a prototype
let StudentPrototype = {
    name: '',
    id: 0,
    gpa: 0.0,
    displayInfo: function() {
        return `${this.name}, ID: ${this.id}, GPA: ${this.gpa}`;
    }
};

let student3 = Object.create(StudentPrototype);
student3.name = "Taylor";
student3.id = 789012;
student3.gpa = 3.5;
console.log(student3.displayInfo()); // Output: "Taylor, ID: 789012, GPA: 3.5"

// ES6 Class Syntax
class StudentClass {
    constructor(name, id, gpa) {
        this.name = name;
        this.id = id;
        this.gpa = gpa;
    }

    displayInfo() {
        return `${this.name}, ID: ${this.id}, GPA: ${this.gpa}`;
    }
}

let student4 = new StudentClass("Morgan", 456789, 3.9);
console.log(student4.displayInfo()); // Output: "Morgan, ID: 456789, GPA: 3.9"
