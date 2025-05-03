#ifndef ANGLER_H
#define ANGLER_H
#include <string>
#include "Bag.h"
using namespace std;

class Angler {
    private:
        string name;
        Bag bag;
    public:
        Angler(const string& name);
        string getName() const;
        void greet() const;

        Bag& getBag(); // Return a pointer to the bag
        const Bag& getBag() const; // Return a const pointer to the bag
        bool saveToFile(const string& filename) const; // Save the bag to a file
        bool loadFromFile(const string& filename); // Load the bag from a file
};

#endif // ANGLER_H
