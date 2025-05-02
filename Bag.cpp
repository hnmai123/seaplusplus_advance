#include "Bag.h"

Bag::Bag() {} // Constructor implementation

Bag::~Bag() {
    for (auto creature : creatures) {
        delete creature; // Delete each SeaCreature object
    }
    creatures.clear(); // Clear the vector
}

void Bag::addCreature(SeaCreature* creature) {
    if (creature != nullptr) {
        creatures.push_back(creature); // Add the creature to the vector
    }
}

const vector<SeaCreature*>& Bag::getCreatures() const {
    return creatures; // Return the vector of SeaCreatures
}

