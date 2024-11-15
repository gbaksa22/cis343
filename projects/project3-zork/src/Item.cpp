#include "Item.h"
#include <iostream>

// Constructor
Item::Item(const std::string& name, const std::string& description, int weight) {
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
    if (weight < 0 || weight > 1000) {
        std::cout << "Error: Amount must be between 0 and 1000.\n";
        this->weight = 0;
    } else {
        this->weight = weight;
    }
}

// Getters
std::string Item::get_name() const {
    return name;
}

std::string Item::get_description() const {
    return description;
}

int Item::get_weight() const {
    return weight;
}

// Overloaded stream operator
std::ostream& operator<<(std::ostream& os, const Item& item) {
    os << item.name << " (Weight: " << item.weight << ") - " << item.description;
    return os;
}
