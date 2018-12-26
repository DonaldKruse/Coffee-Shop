#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
    private:
        std::string _name;
        std::string _description;
        double _price;
        double _work;
        Item();
    public:
        // constructors
        Item ( const std::string name,
                const std::string description,
                double price,
                const double work);

        Item( const Item &); // copy constructor

        // getters
        std::string get_name() const;
        std::string get_description() const;
        double get_price() const { return _price; }
        double get_work() const { return _work; }

        // setters
        void set_description(std::string description) { 
            _description = description;
        }

        void set_price( double price) { _price = price; }

        // destructor
        ~Item();
};

#endif // ITEM_H
