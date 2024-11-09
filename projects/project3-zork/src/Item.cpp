#include "Item.h"
#include <iostream>

// Constructor
Item::Item(const std::string& name, const std::string& description, int amount) {
    // Name
    if (name.empty()) {
        std::cout << "Error: Name is blank.\n";
        this->name = "Unnamed Item";
    } else {
        this->name = name;
    }

    // Description
    if (description.empty()) {
        std::cout << "Error: Description is blank.\n";
        this->description = "No description";
    } else {
        this->description = description;
    }

    // Amount
    if (amount < 0 || amount > 1000) {
        std::cout << "Error: Amount must be between 0 and 1000.\n";
        this->amount = 0;
    } else {
        this->amount = amount;
    }
}

// Getters
std::string Item::get_name() const {
    return name;
}

std::string Item::get_description() const {
    return description;
}

int Item::get_amount() const {
    return amount;
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.name << " (" << item.amount << " amount) - " << item.description;
    return os;
}
