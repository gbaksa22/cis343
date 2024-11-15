#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include <iostream>

class Item {
    public:
        // Constructor
        Item(const std::string& name, const std::string& description, int weight);

        // Getters
        std::string get_name() const;
        std::string get_description() const;
        int get_weight() const;

        // Overloaded stream operator
        friend std::ostream& operator<<(std::ostream& os, const Item& item);

    private:
        std::string name;
        std::string description;
        int weight;
};

#endif

