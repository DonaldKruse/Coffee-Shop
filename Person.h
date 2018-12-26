#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Item.h"
#include <array>
#include <unordered_set>

// nil used as a NaN type
enum Gender {male, female, other, nil};

class Person {
    private:
        std::string _name;
        unsigned int _age;
        Gender _gender;
        double _money = 0.0;
        // TODO add container for Item
    public:
        // constructors
        Person(); // Default constructor
        Person (const std::string name, 
                unsigned int age, 
                Gender gender,
                double money = 0.0);
        Person(const Person &); // copy constructor
        
        // getters
        std::string get_name();
        unsigned int get_age();
        Gender get_gender();

        // setters
        void set_name(std::string name);
        void set_age(unsigned int age);
        void set_money(double money);
        void set_gender(Gender newgender);
        void inc_age();

        // destructor
        ~Person();
};

#endif // PERSON_H
