#include "Angler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "InvertebrateCreature.h"
#include "VertebrateCreature.h"
#include <filesystem>

using namespace std;
namespace fs = filesystem;

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

bool Angler::saveToFile(const string& filename) const {
    fs::create_directories("angler_bags"); // Create the directory if it doesn't exist
    string fullPath = "angler_bags/" + filename; // Full path to the file
    ofstream outputFile(fullPath);
    if (!outputFile) {
        cout << "❌ Error opening file for writing: " << fullPath << endl;
        return false;
    }

    outputFile << name << endl; // Save the angler's name

    for (const SeaCreature* creature : bag.getCreatures()) {
        string type = creature->getType();
        outputFile << type << ","; // Save the type of the creature
        outputFile << creature->getSpecie() << ",";
        outputFile << creature->getSize() << ",";
        outputFile << creature->getQuantity();

        if (type == "Invertebrate") {
            const InvertebrateCreature* invertebrate = dynamic_cast<const InvertebrateCreature*>(creature);
            if (invertebrate) {
                outputFile << "," << invertebrate->getHasEggs(); // Save the hasEggs property
            }
        }
        outputFile << endl; // Add a newline for separation
    }
    outputFile.close();
    cout << "✅ Angler and bag saved to file: " << fullPath << endl;
    return true; 
}

bool Angler::loadFromFile(const string& filename) {
    fs::create_directories("angler_bags"); // Create the directory if it doesn't exist
    string fullPath = "angler_bags/" + filename; // Full path to the file
    ifstream inputFile(fullPath);
    if (!inputFile) {
        cout << "❌ Error opening file for reading: " << fullPath << endl;
        return false;
    }

    bag = Bag(); // Clear the current bag
    string line;
    if (getline(inputFile, line)) {
        name = line; // Load the angler's name
    }

    while (getline(inputFile, line)) {
        stringstream ss(line);
        string type, specie, sizeStr, quantityStr, hasEggsStr;
 
        getline(ss, type, ',');
        getline(ss, specie, ',');
        getline(ss, sizeStr, ',');
        getline(ss, quantityStr, ',');
        getline(ss, hasEggsStr, ',');

        float size = stof(sizeStr);
        int quantity = stoi(quantityStr);
        SeaCreature* creature = nullptr;

        if (type == "Invertebrate") {
            bool hasEggs = (hasEggsStr == "1");
            creature = new InvertebrateCreature(specie, size, quantity, hasEggs);
        } else {
            creature = new VertebrateCreature(specie, size, quantity);
        }

        bag.addCreature(creature); // Add the creature to the bag

    }
    inputFile.close();
    cout << "📦 Loaded bag of " << name << " from: " << fullPath << endl;
    return true; 
}