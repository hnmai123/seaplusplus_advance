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
├── SeaCreature.cpp / SeaCreature.h # Abstract base class for all sea creatures
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

## 📊 UML Diagram
The following UML diagram represents the updated architecture of Sea++ after the enhancements in Part III.

🧩 **Design Patterns Used**:
- `<<facade>>` — **App**: Orchestrates user interaction, bag logic, and system flow.
- `<<mediator>>` — **SeaPlusPlusEngine**: Mediates rule checking between sea creatures and checkers.
- `<<interface>>` — **SeaChecker**: Shared contract for both `VertebrateChecker` and `InvertebrateChecker`.
  
📐 **New & Updated Components**:
- **Angler**: Now owns a `Bag` and has methods to `saveToFile()` and `loadFromFile()`.
- **Bag**: Holds a collection of `SeaCreature*`, using `addCreature()` and `getCreatures()`.
- **BagChecker**: Validates all contents of a Bag via `checkBag()`, using the shared `SeaPlusPlusEngine`.
  
🔁 **Key Relationships**:
- `App` uses `SeaPlusPlusEngine`, `BagChecker`, and owns an `Angler`
- `Angler` ⟶ ◇ `Bag` (composition)
- `Bag` ⟶ ◇ `SeaCreature*` (composite relationship)
- `BagChecker` ⟶ uses `SeaPlusPlusEngine`
  
![Part2_UML drawio](https://github.com/user-attachments/assets/2eb0a10d-e4ce-4021-abe5-ca9ee3896896)

## 🚀 How to Build & Run
Follow these steps to build and run the project manually:
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
