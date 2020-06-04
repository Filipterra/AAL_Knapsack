/**
 * @file CommandInterpreter.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Command interpreter class implementation.
 * 
 */

#include "CommandInterpreter.h"

using namespace Knapsack;

template<> void CommandInterpreter::runCommand<Commands::HELP>() {

}

template<> void CommandInterpreter::runCommand<Commands::RUN>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::GENERATE>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::TEST>() {
    
}

void CommandInterpreter::interprete (std::string command) {
    
    if (command == "-help")
    {
        runCommand<Commands::HELP>();
    }
    else if (command == "-run")
    {
        runCommand<Commands::RUN>();
    }
    else if (command == "-generate")
    {
        runCommand<Commands::GENERATE>();
    }
    else if (command == "-test")
    {
        runCommand<Commands::TEST>();
    }
    else
    {
        std::cout << "Unknown command. Type -help for instructions.\n";
    }
    
}