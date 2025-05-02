#include "App.h"
#include <iostream>
#include "VertebrateCreature.h"
#include "InvertebrateCreature.h"
#include <algorithm>
#include "BagChecker.h"
#include "InputHelper.h"

using namespace std;

App::App() {
    engine = new SeaPlusPlusEngine("regulation/vertebrate_rules.csv", "regulation/invertebrate_rules.csv");
    angler = nullptr;
    bagChecker = new BagChecker("regulation/vertebrate_rules.csv", "regulation/invertebrate_rules.csv");
}

App::~App() {
    delete engine;
    delete angler;
    delete  bagChecker;
}

void App::run() {
    cout << "\n🌊 Welcome to Sea++!\n=======================================" << endl;
    string name;    
    name = readString("👤 Enter your name: ");
    cout << endl;
    angler = new Angler(name);
    angler->greet();
    cout << "\n🎣 Let's check your bag!" << endl;
    
    while (true) {
        cout << "\n 🎣 Menu: " << endl;
        cout << "1️⃣ Add a new catch" << endl;
        cout << "2️⃣ Check your bag" << endl;
        cout << "3️⃣ Exit" << endl;
        int choice = readInt("🔍 Choose an option: ");
        cout << "=======================================" << endl;

        if (choice == 1) {
            SeaCreature* creature = getCatchData();
            angler->getBag().addCreature(creature);
            cout << "✅ Catch added to your bag!" << endl;
            displayCatchData(creature);
            displayResult(engine->checkCatch(creature));
        } else if (choice == 2) {
            checkBag(); // Check the bag for valid catches
        } else if (choice == 3) {
            displayGoodbye();
            break; // Exit the loop
        } else {
            cout << "⚠️ Invalid choice. Please try again." << endl;
            break;
        }
    }
}

SeaCreature* App::getCatchData() {
    string specie, type;
    float size;
    int quantity;
    cout << "🐠 Please enter details about your sea creature\n";
    cout << "-------------------------------------------------\n";
    type = toLower(readString("🌊 Type (Vertebrate / Invertebrate): "));
    specie = readString("🔖 Species name: ");
    size = readFloat("📏 Size (in cm): ");
    quantity = readInt("🔢 Quantity caught: ");
    cout << "-------------------------------------------------\n";

    // Create a new SeaCreature object based on the type
    SeaCreature* creature;
    if (type == "vertebrate") {
        creature = new VertebrateCreature(specie, size, quantity);
    } else if (type == "invertebrate") {
        cout << "\n🔸🔸🔸 Invertebrate Details 🔸🔸🔸\n";
        bool hasEggs = readYesNo("🥚 Has eggs?");        
        creature = new InvertebrateCreature(specie, size, quantity, hasEggs);
    } else {
        cout << "\n==============================\n";
        cout << "⚠️  Unknown type entered!\n";
        cout << "🔁 Defaulting to Vertebrate.\n";
        cout << "==============================\n";        
        creature = new VertebrateCreature(specie, size, quantity);
    }
    return creature;
}

void App::displayCatchData(SeaCreature* creature) {
    cout << "\n🐟 Sea Creature Details\n-------------------------\n";
    cout << "🔖 Species  : " << creature->getSpecie() << "\n";
    cout << "📏 Length   : " << creature->getSize() << " cm\n";
    cout << "🧬 Type     : " << creature->getType() << "\n";
    cout << "🔢 Quantity : " << creature->getQuantity() << "\n";

    const InvertebrateCreature* inv = dynamic_cast<InvertebrateCreature*>(creature);
    if (inv) {
        cout << "🥚 Has Eggs : " << (inv->getHasEggs() ? "Yes" : "No") << "\n";
    }
    cout << "-------------------------\n";
}

void App::displayResult(bool result) {
    if (result) {
        cout << "\n✅ You can keep the catch!" << endl;
    } else {
        cout << "\n❌ You must release the catch back to nature!" << endl;
    }
}

void App::displayGoodbye() {
    cout << "=======================================\n";
    cout << "🎣 Thank you for using Sea++!\n";
    cout << "💧 Respect the ocean. Fish responsibly.\n";
    cout << "👋 Goodbye, and tight lines!\n";
    cout << "=======================================" << endl;
}

void App::checkBag() {
    cout << "\n🔎 Checking entire bag...\n";
    bagChecker->checkBag(&angler->getBag());
}