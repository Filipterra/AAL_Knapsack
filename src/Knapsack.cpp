/**
 * @file Knapsack.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Main function file.
 * 
 */

#include <iostream>
#include <string>
#include "CommandInterpreter.h"

/**
 * @brief Main program function. Here the execution starts and ends.
 * 
 * @return int 0 - if closed normally
 */
int main(int argc, char * argv[])
{
    if ( argc < 2 || (argc < 3 && (strcmp(argv[1], "-help")!=0)) ) {
        std::cout << "Please provide a known command. Type -help for more information.\n";
        return 1;
    }

    std::string command(argv[1]);
    std::string algorithm;
    if (argc>2) algorithm = std::string(argv[2]);

    Knapsack::CommandInterpreter::interprete(command, algorithm);

    return 0;
}
