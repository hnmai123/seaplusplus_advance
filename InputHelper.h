#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>
using namespace std;

string toLower(const string& str); // Function to convert a string to lowercase
float readFloat(const string& prompt); // Function to read a float from user input
int readInt(const string& prompt); // Function to read an integer from user input
string readString(const string& prompt); // Function to read a string from user input
bool readYesNo(const string& prompt); // Function to read a boolean from user input
// Function to read a file name from user input with a specific pattern "filename.csv"
string readFileName(const string& prompt, const string& pattern = "^[\\w\\-. ]+\\.csv$"); 

#endif // INPUTHELPER_H