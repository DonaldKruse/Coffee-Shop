#include <iostream>
#include <string>
#include "Item.h"


// Constructor
// TODO add exceptions that use exception class for 
//  bad values.
Item::Item ( const std::string name,
             const std::string description,
             double price,
             double work) {

    _name = name;

    _description = description;

    if ( price < 0.0 ) {
        std::cout << "Warning: " << name << " has input price of " 
                  << price << "dollars. " << "Setting _price to 0.0 dollars." 
                  << std::endl;
        _price = 0.0;
    } else {
        _price = price;
    }
    
    if ( work < 0.0 ) {    
        std::cout << "Warning: " << name << " has input work of " 
                  << work << ". " << "Setting _work to 0.0." 
                  << std::endl;
        _work = 0.0;
    } else {
        _work = work;
    }
}

// Copy constructor
Item::Item(const Item & i ) {
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


// Implemented in Item.h
//double Item::get_price() {
//    return _price;
//}
//
//double Item::get_work() {
//    return _work;
//}

// -- Setters --

// Implemented in Item.h
//void Item::set_description(std::string description) {
//    _description = description;
//}
//
//void Item::set_price(double price) {
//    _price = price;
//}


// Destructor
Item::~Item() {}
