/// @file code-hex.cpp
/// @author Rixen Usam
/// @date 5/14/23
/// @brief Takes the hex values from a file and converts them to decimal
/// values and displays them in a matrix
/// @note Read in the file and convert the hex values and then display the same
///       matrix with decimal numbers.


#include <iostream>
#include <fstream>
#include <cmath>
#include <complex>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string data;    // Holds the input from the infile
    // Array to hold the hex numbers
    int k[10][10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};
    // Open the file
    ifstream infile;
    infile.open("hex_table.txt");

    // Loop until the end of the file
    while (!infile.eof())
    {
        // Nested loop to insert hex into double array
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // Reads in the string hex values
                getline(infile, data, ' ');
                // Converts string to dec int values in array
                k[i][j] = stoi(data, 0, 16);
                // Displays the new dec table values in matrix
                cout << left << setw(4) << k[i][j] << " ";
            }
        // Makes sure every 10 values goes to next line
        cout << endl;
        }
    }

    infile.close();

    return (0);

}
