#ifndef BAG_H
#define BAG_H

#include <vector>
#include "SeaCreature.h"
using namespace std;

class Bag {
    private:
        vector<SeaCreature*> creatures; // Vector to hold pointers to SeaCreature objects
    public:
        Bag(); // Constructor
        ~Bag(); // Destructor
        void addCreature(SeaCreature* creature); // Method to add a SeaCreature to the bag
        void removeCreature(SeaCreature* creature); // Method to remove a SeaCreature from the bag
        const vector<SeaCreature*>& getCreatures() const; // Method to get all SeaCreatures in the bag
    
};

#endif // BAG_H