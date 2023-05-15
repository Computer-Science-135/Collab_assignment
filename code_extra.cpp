<<<<<<< HEAD
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
=======
/// @file code_extra.cpp
/// @author Rixen Usam
/// @date 5/14/23
/// @brief Takes a message from a file and sifts through
/// it to find the hidden message
>>>>>>> afb07145dc0adbb7dd587275647822af81e62619
/// @note Read in the file and find the the word EXTRA


#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <cctype>
#include <string>


using namespace std;



int main()
{
    string msg[5] = {};     // Stores hidden message into array
    char c;     // Stores chars from file
    int i = 0;  // The counter for the loop

<<<<<<< HEAD
 // Declare Variables //

    char c;      // Reads each character of file
    string msg;  // Holds the Result of Message
=======
    // Open the hidden text file
    ifstream infile;
    infile.open("hidden.txt");

    // While loop to reach end of the file
    while (!infile.eof())
    {
        // Go through each char to find the hidden message
        infile.get(c);
        // If the char is alphabetical then add to array
        if (isalpha(c))
        {
            msg[i] = c;
            i++;    // Keeps track of chars in hidden msg
        }
    }
>>>>>>> afb07145dc0adbb7dd587275647822af81e62619

    infile.close();

<<<<<<< HEAD
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
=======
    // Loop through array to display message
    for (int j = 0; j < i; j++)
    {
        cout << msg[j];
    }

    cout << endl;

    return (0);
>>>>>>> afb07145dc0adbb7dd587275647822af81e62619

}
