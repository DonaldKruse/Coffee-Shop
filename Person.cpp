#include "Person.h"
#include <string>

// -- implementation --

// default constructor
Person::Person() : _name(""), _age(-1), _gender(nil) {}
Person::Person (const std::string name, 
                unsigned int age, 
                Gender gender, 
                double money) :
    _name(name), _age(age), _gender(gender), _money(money) {};

// copy constructor
Person::Person(const Person & p) {
    _name = p._name;
    _age = p._age;
    _gender = p._gender;
    _money = p._money;
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



Person::~Person() {}

