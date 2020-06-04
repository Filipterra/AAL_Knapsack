/**
 * @file CommandInterpreter.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Command interpreter class implementation.
 * 
 */

#include "CommandInterpreter.h"

using namespace Knapsack;

template<> void CommandInterpreter::runCommand<Commands::HELP, Algorithm::DYNAMIC>() {
    std::cout << "Accepted commands:\n-help -- shows help\n-run -- solve knapsack problem with provided data\n-generate -- solve knapsack problem with data generated"
    << "with provided parameters\n-test -- solve knapsack problem from test problem data generated from preprogrammed parameters\n\n"
    << "Accepted <algorithm> values:\t-brutal\t-dynamic\n\n\n"
    << "Execution methods:\n\nKnapsack -help\n\nKnapsack -run -<algorithm> -- in next line followed by values of: knapsack volume, number of objects,"
    << "maximum nuber of copies; in next lines provide pairs of object value and object volume\n\tExample:\n\t\tKnapsack -run -dynamic\n\t\t10 2 3\n\t\t2 3\n\t\t3 1\n\t\t5 8\n\n"
    << "Knapsack -generate -- in next line followed by generator values of: number of objects, maximum nuber of copies, object volume value range\n\tExample:\n\t\t"
    << "Knapsack -generate -dynamic\n\t\t10 2 100\n\n"
    << "Knapsack -test\n\n";
}

template<> void CommandInterpreter::runCommand<Commands::HELP, Algorithm::BRUTAL>() {
    runCommand<Commands::HELP, Algorithm::DYNAMIC>();
}

template<> void CommandInterpreter::runCommand<Commands::RUN, Algorithm::BRUTAL>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::RUN, Algorithm::DYNAMIC>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::GENERATE, Algorithm::BRUTAL>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::GENERATE, Algorithm::DYNAMIC>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::TEST, Algorithm::BRUTAL>() {
    
}

template<> void CommandInterpreter::runCommand<Commands::TEST, Algorithm::DYNAMIC>() {
    
}

void CommandInterpreter::interprete (std::string command, std::string algorithm) {
    
    if (command == "-help")
    {
        runCommand<Commands::HELP, Algorithm::DYNAMIC>();
        return;
    }
    else if (command == "-run")
    {
        if (algorithm == "-brutal")
        {
            runCommand<Commands::RUN, Algorithm::BRUTAL>();
            return;
        }
        else if (algorithm == "-dynamic")
        {
            runCommand<Commands::RUN, Algorithm::DYNAMIC>();
            return;
        }
    }
    else if (command == "-generate")
    {
        if (algorithm == "-brutal")
        {
            runCommand<Commands::GENERATE, Algorithm::BRUTAL>();
            return;
        }
        else if (algorithm == "-dynamic")
        {
            runCommand<Commands::GENERATE, Algorithm::DYNAMIC>();
            return;
        }
    }
    else if (command == "-test")
    {
        if (algorithm == "-brutal")
        {
            runCommand<Commands::TEST, Algorithm::BRUTAL>();
            return;
        }
        else if (algorithm == "-dynamic")
        {
            runCommand<Commands::TEST, Algorithm::DYNAMIC>();
            return;
        }
    }
    std::cout << "Unknown command. Type -help for instructions.\n";
}