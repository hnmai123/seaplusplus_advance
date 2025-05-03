# Sea++ (Part III)

## 🎣 Description
This version of **Sea++** extends the fishing rule validation system to allow:
- Management of multiple sea creatures in a `Bag`
- Validation of entire bags using a `BagChecker`
- Saving/loading `Angler` data and catches to/from files
- Clean and safe user input using a helper class
The system builds on the design patterns from Part I and demonstrates more advanced use of C++ features, file I/O, and object-oriented principles.

## 🧠 Design Patterns Used
- **Facade** – `App` handles all user interaction
- **Mediator** – `SeaPlusPlusEngine` coordinates validation
- **Interface** – `SeaChecker` provides a unified contract for checkers
- **Composite-like behavior** – `Bag` contains a collection of `SeaCreature` objects, validated as a group

## 📁 File Structure
<pre>
├── App.cpp / App.h                 # Facade class, updated to support Bag and load/save
├── Angler.cpp / Angler.h           # Now includes Bag saving/loading
├── Bag.cpp / Bag.h                 # Holds multiple SeaCreature objects
├── BagChecker.cpp / BagChecker.h   # Validates all contents of a Bag using engine
├── CSVLoader.cpp / CSVLoader.h     # Loads species rule data from CSV
├── SpeciesRule.h                   # Struct definition for species size and bag limit rules
├── SeaCreature                     # Abstract base class for all sea creatures
├── VertebrateCreature.cpp / .h     # Represents vertebrate species (no eggs)
├── InvertebrateCreature.cpp / .h   # Represents invertebrate species (may have eggs)
├── SeaChecker.h                    # Rule validators for each creature type
├── InvertebrateChecker.cpp / .h    # Validates invertebrate creatures against rules
├── VertebrateChecker.cpp / .h      # Validates vertebrate creatures against rules
├── SeaPlusPlusEngine.cpp / .h      # Mediator pattern between checkers
├── InputHelper.cpp / InputHelper.h # Handles safe user input (with validation and formatting)
├── regulation/                     # Folder containing CSV rule files (size/bag limits)
├── main.cpp                        # Entry point
├── CMakeLists.txt                  # CMake build configuration file
</pre>

## 📊 UML Diagram (Updated)

The updated UML diagram reflects:

- The new `Bag` and `BagChecker` classes
- Composition relationship between `Bag` ◇─── `SeaCreature`
- `Angler` owns a `Bag`
- File I/O methods such as `saveToFile()` and `loadFromFile()`
  
![Part2_UML drawio](https://github.com/user-attachments/assets/2eb0a10d-e4ce-4021-abe5-ca9ee3896896)

## 🚀 How to Build & Run
```bash
# Step 1: Create the build directory
mkdir build
cd build
# Step 2: Generate the build files
cmake ..
# Step 3: Build the project
make
# Step 4: Run the program
./SeaPlusPlus
