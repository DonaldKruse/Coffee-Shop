#include <iostream>
#include <string>
#include <vector>
#include "Person.h"
#include "Item.h"

int main(int argc, char* argv[]) {
    /*
     * Test class Person
     * Declare vector of Person objects
     * push_back Beth and Donny instances and then display
     */
    std::cout << "Testing class Person..." << std::endl;    
    std::vector<Person> people;
    people.push_back(Person("Donny", 27, male));
    people.push_back(Person("Beth", 24, female));
    for (auto person = people.begin(); person != people.end(); person++) {
        std::cout << "My name is " << person->get_name() << "." << std::endl;
    }
    people[0].set_name("Donald");
    for (auto person = people.begin(); person != people.end(); person++) {
        std::cout << "My name is " << person->get_name() << "." << std::endl;
    }
    std::cout << "use copy constructor on beth" << std::endl;
    Person beth = Person("Beth", 24, female);
    Person beth2(beth);
    std::cout << "testing all the functions" << std::endl;
    std::cout << "Name: " << beth2.get_name() << std::endl;
    std::cout << "Age: " << beth2.get_age() << std::endl;
    std::cout << "Gender: " << beth2.get_gender() << std::endl;
    std::cout << "Set name to 'beth2': " << std::endl;
    beth2.set_name("beth2");
    std::cout << "Name: " << beth2.get_name() << std::endl;
    std::cout << "Inc age: " << std::endl;
    beth2.inc_age();
    std::cout << "Age: " << beth2.get_age() << std::endl;
    std::cout << "set age: " << std::endl;
    beth2.set_age(24); 
    std::cout << "Age: " << beth2.get_age() << std::endl;
    std::cout << "Set gender: " << std::endl;
    beth2.set_gender(other);
    std::cout << "Gender: " << beth2.get_gender() << std::endl;

    // Test class Item in same way as class Person
    std::cout << "Testing class Item..." << std::endl;    
    std::vector<Item> items;
    items.push_back( Item("small coffee", "A small coffe without cream or sugar",
                           1.95, 0.2) );
    for (auto item = items.begin(); item != items.end(); item++) {
        std::cout << "This item is a "
                  << item->get_name()
                  << " with the description: "
                  << "'" << item->get_description() <<"'"
                  << " and costs " << "$" << item->get_price()
                  << " and takes " << item->get_work() << " work."
                  << std::endl;
    }
    return 0;
}

