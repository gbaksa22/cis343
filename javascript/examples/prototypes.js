// Base prototype for Person
function Person(name, age) {
    this.name = name;
    this.age = age;
}

Person.prototype.greet = function() {
    return `Hello, my name is ${this.name}.`;
};

// Prototype for Student, inheriting from Person
function Student(name, age, grade) {
    Person.call(this, name, age);  // Call Person's constructor with 'this' context
    this.grade = grade;
}

// Inherit the Person prototype
Student.prototype = Object.create(Person.prototype);
Student.prototype.constructor = Student;

Student.prototype.study = function() {
    return `${this.name} is studying.`;
};

// Prototype for Teacher, inheriting from Person
function Teacher(name, age, subject) {
    Person.call(this, name, age);  // Call Person's constructor with 'this' context
    this.subject = subject;
}

// Inherit the Person prototype
Teacher.prototype = Object.create(Person.prototype);
Teacher.prototype.constructor = Teacher;

Teacher.prototype.teach = function() {
    return `${this.name} is teaching ${this.subject}.`;
};

// Creating instances of Student and Teacher
let alice = new Student("Alice", 20, "Sophomore");
let mrSmith = new Teacher("Mr. Smith", 45, "Math");

// Accessing properties and methods
console.log(alice.greet());        // "Hello, my name is Alice."
console.log(alice.study());        // "Alice is studying."
console.log(mrSmith.greet());      // "Hello, my name is Mr. Smith."
console.log(mrSmith.teach());      // "Mr. Smith is teaching Math."

// Prototype chain demonstration
console.log(alice instanceof Student);     // true
console.log(alice instanceof Person);      // true
console.log(mrSmith instanceof Teacher);   // true
console.log(mrSmith instanceof Person);    // true
