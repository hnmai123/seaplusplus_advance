#include "BagChecker.h"
#include <iostream>

using namespace std;

BagChecker::BagChecker(const string& vertebrateFile, const string& invertebrateFile) {
    engine = new SeaPlusPlusEngine(vertebrateFile, invertebrateFile); // Initialize the SeaPlusPlusEngine instance
}
    
BagChecker::~BagChecker() { 
    delete engine; // Clean up the SeaPlusPlusEngine instance
}
void BagChecker::checkBag(const Bag* bag) const {
    bool allValid = true;
    int passedChecks = 0;
    int failedChecks = 0;

    for (const SeaCreature* creature : bag->getCreatures()) {
        cout << "----------------------------------------" << endl;
        cout << "\n🔍 Checking: " << creature->getSpecie() << endl;
        bool result = engine->checkCatch(creature);

        if (!result) {
            cout << "❌ Issue found with: " << creature->getSpecie() << endl;
            allValid = false;
            failedChecks++;
        } else {
            cout << "✅ " << creature->getSpecie() << " passed all checks." << endl;
            passedChecks++;
        }
    }
    cout << "----------------------------------------" << endl;
    cout << "\n📦 Bag Summary" << endl;
    cout << "----------------------------------------" << endl;
    cout << "✅ Valid creatures : " << passedChecks << endl;
    cout << "❌ Invalid creatures : " << failedChecks << endl;

    if (allValid) {
        cout << "\n=============================" << endl;
        cout << "🎉 All creatures in the bag are valid! ✅" << endl;
        cout << "🧺 You may keep your catch." << endl;
        cout << "=============================" << endl;    } 
    else {
        cout << "\n🚨 Bag Validation Warning 🚨" << endl;
        cout << "⚠️  Some creatures in the bag did not pass rule checks." << endl;
        cout << "🔁 Please release any invalid catches." << endl;    
    }
    cout << "----------------------------------------" << endl;
}