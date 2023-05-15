/// @file code_extra.cpp
/// @author Rixen Usam
/// @date 5/14/23
/// @brief Takes a message from a file and sifts through
/// it to find the hidden message
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

    infile.close();

    // Loop through array to display message
    for (int j = 0; j < i; j++)
    {
        cout << msg[j];
    }

    cout << endl;

    return (0);

}
