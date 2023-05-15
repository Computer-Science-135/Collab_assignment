/// @file code-hex.cpp
/// @author  Alan Oliva
/// @date    05/14/2023
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief   The program reads the file of a hexadecimal table and
///          converts each hex into a decimal and is then written to
///          a text file resulting in a new file with the new, converted
///          decimals in a table format.
/// @note    150 minutes
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



int main() {

       // Open the Input and Output Files
    ifstream infile("hex_table.txt");
    ofstream outfile("dec_table.txt");

       // Declared Variables for Main
    string hex;
    int count = 1;

       // Will not exit loop until their is no more
       // inputs in the stream
    while (infile >> hex) {

           // Declare Local Variables //

        int decimal = 0;  // Converted Hex number

           // Ignores the first two characters that signifies
           // the string is a hexadecimal
        int square = static_cast<int>(hex.size()) - 3;

           // iterates the last two characters of the hex
           // and calculates the value and multiple by 16 to
           // the power of the hex position.
        for (unsigned i = 2; i < hex.size(); i++) {

            const char c = hex.at(i);  // assign character
            int digit = 0;             // accumulates decimal total

               // Converts character to integer
            if (isdigit(c) != 0) {
                digit = c - '0';
            }
            if (c >= 'a' && c <= 'f') {
                digit = c - 'a' + 10;
            }

               // Total into decimal (determine if multiply)
            decimal += (square != 0)? digit * 16 : digit;
            square--;
        }
        count++;  // Increments position of table

           // Writes data to newly opened file
        outfile << setw(4) << decimal << " ";

           // Will move the position of the numbers to
           // the next line to set a 10 column format table
        if (count > 10) {
            outfile << endl;
            count = 1;  // reset position
        }
    }
       // Close Files
    infile.close();
    outfile.close();
    cout << endl;
return (0);
}
