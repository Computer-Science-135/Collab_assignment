/// @file  code_extra.cpp
/// @author  Alan Oliva
/// @date    05/14/2023
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief   The program reads in a file and iterate each
///          character and if it is not a number it will
///          create and concatenate the found character to
///          reveal the message.
/// @note    10 minutes
/// @note Read in the file and find the the word EXTRA


#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <cctype>
#include <string>


using namespace std;



int main() {

 // Declare Variables //

    char c;      // Reads each character of file
    string msg;  // Holds the Result of Message


       // Create File Stream //
    ifstream infile;
    infile.open("hidden.txt");

       // Loop each character found in the file
       // and if it is not a number, it will create
       // the message in a string one by one character.
    while (!infile.eof()) {
        infile >> c;
        if (isdigit(c) != 0) {
            msg += c;
        }
    }
    infile.close();

       // Display Message
    cout << endl << msg << endl << endl;

return (0);

}
