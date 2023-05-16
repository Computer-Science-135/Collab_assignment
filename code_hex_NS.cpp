/// @file code_hex_NS.cpp
/// @author Natalia Smorodinova
/// @date May 15, 2023
/// @note I pledge my word of honor that I have abided by the
/// CSN Academic Integrity Policy while completing this assignment.
/// @brief the program converts hex to decimal 
///
/// @note People who helped me: Natalia Smorodinova


// 12345678901234567890123456789012345678901234567890123456789012345678901234567890


#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

int main() {
    // Open the file containing hexadecimal numbers for reading
    std::ifstream inputFile("hex_table.txt");

    // Open a new file for writing the converted decimal numbers
    std::ofstream outputFile("dec_table.txt");

    // String to store each hexadecimal number
    std::string hexNumber;

    // Read each line from the input file
    while (getline(inputFile, hexNumber)) {
        std::istringstream iss(hexNumber);

        // Read each hexadecimal number from the line
        while (iss >> hexNumber) {

            // Variable to store the converted decimal number
            unsigned long decimalNumber = 0;

            // Create a stringstream for the conversion
            std::stringstream ss;

            // Input the hexadecimal number into the stringstream
            ss << std::hex << hexNumber;

            // Extract the converted decimal number from the stringstream
            ss >> decimalNumber;

            // Write the decimal number to the output file
            outputFile << std::setw(4) << std::setfill(' ') << decimalNumber;
        }

        outputFile << std::endl;
    }

    // Close the input and output files after the conversion
    inputFile.close();
    outputFile.close();

    // Notify the user that the conversion has been completed
    std::cout << "Conversion completed! Decimals saved to dec_table.txt"
              << std::endl;

    return 0;
}