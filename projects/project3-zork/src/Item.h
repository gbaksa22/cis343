#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item {
    public:
        // Constructor
        Item(const std::string& name, const std::string& description, int amount);

        // Getters
        std::string get_name() const;
        std::string get_description() const;
        int get_amount() const;

        // Overloaded stream operator
        friend std::ostream& operator<<(std::ostream& os, const Item& item);

    private:
        std::string name;
        std::string description;
        int amount;
};

#endif

