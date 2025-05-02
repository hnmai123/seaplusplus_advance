#include "Angler.h"
#include <iostream>
using namespace std;

Angler::Angler(const string& name) : name(name) {}

string Angler::getName() const {
    return name;
}

void Angler::greet() const {
    cout << "Hello " << name << "! 🎣 Let's get fishing!" << endl;
    cout << "=======================================" << endl;
}

Bag& Angler::getBag() {
    return bag; // Return a reference to the bag
}

const Bag& Angler::getBag() const {
    return bag; // Return a const reference to the bag
}