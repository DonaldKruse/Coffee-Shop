#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Item.h"
#include <array>
#include <map>

// nil used as a NaN type
enum Gender {male, female, other, nil};

class Person {
    private:
        std::string _name;
        unsigned int _age;
        Gender _gender;
        double _money = 0.0;
        // TODO add container for Item
        // TODO determine if bag is its own class
        const unsigned int _max_bag_size = 2;
        std::map<std::string, Item> _bag;

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
        
        // functions for bag
        void add_item(Item it);
        void remove_item(Item it);
        void remove_item(std::string it_name);
        // TODO add a view_items function

        // TODO add a give item that takes Person p1 and Person p2 and 
        // gives item from p2 to p1, e.g.,
        //
        //    p1 << p2.give_item("foobar");
        // or
        //
        //    Person_Namespace::give_item(source_person, dest_person, item_name);


        // destructor
        ~Person();
};

#endif // PERSON_H
