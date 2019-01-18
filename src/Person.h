#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include "Item.h"
#include <array>
#include <map>

// nil used as a NaN type
enum Gender {male, female, other, nil};


// TODO(DonaldKruse)
class Person {
    private:
        std::string _name;
        unsigned int _age;
        Gender _gender;
        double _money;
        unsigned int _bag_size;
        std::map<std::string, Item> _bag;

    public:
        // constructors
        Person();
        Person (const std::string name,
                unsigned int age,
                Gender gender,
                double money = 0.0,
                unsigned int bag_size = 2);
        Person(const Person &);  // copy constructor

        // getters
        std::string get_name();
        unsigned int get_age();
        Gender get_gender();

        // setters
        void set_name(std::string name);
        void set_age(unsigned int age);
        void set_money(double money);
        void set_gender(Gender newgender);
        void increment_age();

        // functions for bag
        void add_item(Item it);
        void remove_item(Item it);
        void remove_item(std::string it_name);
        unsigned int get_bag_size();

        // TODO(DonaldKruse): add a view_items function

        // TODO(DonaldKruse): add a give item that takes Person p1 and Person p2 and
        // gives item from p2 to p1, e.g.,
        //
        //    p1 << p2.give_item("foobar");
        // or
        //
        //    Person_Namespace::give_item(source_person, dest_person, item_name);


        ~Person();
};

#endif  // PERSON_H_
