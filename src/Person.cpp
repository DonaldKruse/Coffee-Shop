#include "Person.h"
#include "Item.h"
#include <string>
#include <map>
#include <iostream>

// -- implementation --

// default constructor
Person::Person() : _name(""), _age(-1), _gender(nil) {}
Person::Person (const std::string name, 
                unsigned int age, 
                Gender gender, 
                double money,
                unsigned int bag_size) :
    
                _name(name),
                _age(age),
                _gender(gender),
                _money(money),
                _bag_size(bag_size) 
                {}


// copy constructor
Person::Person(const Person & p) {
    _name = p._name;
    _age = p._age;
    _gender = p._gender;
    _money = p._money;
    _bag_size = p._bag_size;
    _bag = p._bag;
}

// -- Getters --

std::string Person::get_name() {
    return _name;
}

unsigned int Person::get_age() {
    return _age;
}

Gender Person::get_gender() {
    return _gender;
}


// -- Setters --

void Person::set_name(std::string name) {
    _name = name;
}

void Person::set_age(unsigned int age) {
    _age = age;
}

void Person::set_money(double money) {
    _money = money;
}

void Person::set_gender(Gender new_gender) {
    _gender = new_gender;
}

void Person::inc_age() {
    ++_age;
}

// -- functions for bag --

void Person::add_item(Item it) {
    if (_bag.size() < _bag_size) {
        _bag.insert(std::make_pair(it.get_name(), it));
    } else {
        std::cout << "Failed to add " << it.get_name() << " to "
                  << _name <<"'s  bag." << std::endl;
    }
}

void Person::remove_item(Item it) {
    auto search = _bag.find(it.get_name());
    if ( _bag.size() > 0 && search != _bag.end() ) {
        _bag.erase(it.get_name());
    } else {
        std::cout << "Failed to remove " << it.get_name() << " from "
                  << _name <<"'s  bag." << std::endl;
    }
}

void Person::remove_item(std::string it_name) {
    auto search = _bag.find(it_name);
    if ( _bag.size() > 0 && search != _bag.end() ) {
        _bag.erase(it_name);
    } else {
        std::cout << "Failed to remove " << it_name << " from "
                  << _name <<"'s  bag." << std::endl;
    }
}

unsigned int Person::get_bag_size() {
    return _bag_size;
}



Person::~Person() {}

