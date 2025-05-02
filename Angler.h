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
};

#endif // ANGLER_H
