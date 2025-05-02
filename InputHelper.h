#ifndef INPUTHELPER_H
#define INPUTHELPER_H

#include <string>
using namespace std;

float readFloat(const string& prompt); // Function to read a float from user input
int readInt(const string& prompt); // Function to read an integer from user input
string readString(const string& prompt); // Function to read a string from user input
bool readYesNo(const string& prompt); // Function to read a boolean from user input

#endif // INPUTHELPER_H