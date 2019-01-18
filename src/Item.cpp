#include <iostream>
#include <string>
#include "Item.h"


// Constructor
// TODO(DonaldKruse): add exceptions that use exception class for
//                    bad values.
Item::Item(const std::string name,
           const std::string description,
           double price,
           double work) {
    _name = name;
    _description = description;

    // check for valid values
    if (price < 0.0) {
        std::cout << "Warning: " << name << " has input price of "
                  << price << "dollars. " << "Setting _price to 0.0 dollars."
                  << std::endl;
        _price = 0.0;
    } else {
        _price = price;
    }
    if (work < 0.0) {
        std::cout << "Warning: " << name << " has input work of "
                  << work << ". " << "Setting _work to 0.0."
                  << std::endl;
        _work = 0.0;
    } else {
        _work = work;
    }
}


// Copy constructor
Item::Item(const Item & i) {
    _name = i.get_name();
    _description = i.get_description();
    _price = i.get_price();
    _work = i.get_work();
}


// -- Getters --


std::string Item::get_name() const {
    return _name;
}


std::string Item::get_description() const {
    return _description;
}


Item::~Item() {}
