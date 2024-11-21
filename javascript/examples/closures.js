// A closure example to simulate private variables in JavaScript

const createAccount = function(customer) {
    let money = 0;  // This variable is private to the outer function

    return {
        // Inner function to access the private 'money' variable
        getMoney: function() {
            return money;
        },
        // Inner function to add money to the private 'money' variable
        addMoney: function(amount) {
            if (amount > 0) {
                money += amount;
            }
        },
        // Inner function to access the private 'customer' parameter
        getCustomer: function() {
            return customer;
        }
    };
};

// Creating an account instance with a specific customer
const account = createAccount("Alice");

// Accessing the private 'money' variable through closures
console.log(account.getMoney());        // Output: 0
account.addMoney(100);
console.log(account.getMoney());        // Output: 100

// Accessing the customer name through closures
console.log(account.getCustomer());     // Output: "Alice"

// Attempting to access 'money' directly (not allowed)
// console.log(account.money);          // Output: undefined

// Explanation of Closure Mechanism:
// - `createAccount` function creates and returns an object with methods that can access 'money' and 'customer'.
// - `money` and `customer` are not accessible directly from outside `createAccount`.
// - Each method (inner function) retains access to `money` and `customer`, even after `createAccount` finishes running.
// - This is what makes closures useful for data encapsulation and simulating private variables.
