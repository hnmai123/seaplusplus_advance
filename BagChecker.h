#ifndef BAGCHECKER_H
#define BAGCHECKER_H

#include "SeaPlusPlusEngine.h"
#include "Bag.h"
using namespace std;

class BagChecker {
    private:
        SeaPlusPlusEngine* engine; // Pointer to the SeaPlusPlusEngine instance
    public:
        BagChecker(const string& vertebrateFile, const string& invertebrateFile); // Constructor that takes a SeaPlusPlusEngine pointer
        ~BagChecker(); // Destructor
        void checkBag(const Bag* bag) const; // Method to check the bag
};

#endif // BAGCHECKER_H

