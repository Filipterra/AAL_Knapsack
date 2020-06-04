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
    << "maximum nuber of copies; in next lines provide pairs of object value and object volume\n\tExample:\n\t\tKnapsack -run -dynamic\n\t\t10 2 3\n\t\t2 3\n\t\t3 1\n\n"
    << "Knapsack -generate -<algorithm> -- in next line followed by generator values of: number of objects, maximum nuber of copies, object volume value range\n\tExample:\n\t\t"
    << "Knapsack -generate -dynamic\n\t\t10 2 100\n\n"
    << "Knapsack -test -<algorithm>\n\n";
}

template<> void CommandInterpreter::runCommand<Commands::HELP, Algorithm::BRUTAL>() {
    runCommand<Commands::HELP, Algorithm::DYNAMIC>();
}

template<> void CommandInterpreter::runCommand<Commands::RUN, Algorithm::BRUTAL>() {

    DataPointer data = std::make_shared<Data>();
    ValueType object_value;
    VolumeType knapsack_volume, object_volume;
    unsigned int objects_number, copies_number;
    
    //read parameters
    while(std::cin >> knapsack_volume >> objects_number >> copies_number) {
        
        data->setMaxCopies(copies_number);
        data->setVolume(knapsack_volume);

        for (unsigned int i=0; i<objects_number; ++i) {

            std::cin >> object_value >> object_volume;
            data->addObject(object_value, object_volume);
        }

        TestModule::run<Algorithm::BRUTAL>(data);

        data->clear();
    }
}

template<> void CommandInterpreter::runCommand<Commands::RUN, Algorithm::DYNAMIC>() {

    DataPointer data = std::make_shared<Data>();
    ValueType object_value;
    VolumeType knapsack_volume, object_volume;
    unsigned int objects_number, copies_number;
    
    //read parameters
    while(std::cin >> knapsack_volume >> objects_number >> copies_number) {

        data->setMaxCopies(copies_number);
        data->setVolume(knapsack_volume);

        for (unsigned int i=0; i<objects_number; ++i) {

            std::cin >> object_value >> object_volume;
            data->addObject(object_value, object_volume);
        }
        
        TestModule::run<Algorithm::DYNAMIC>(data);

        data->clear();
    }
}

template<> void CommandInterpreter::runCommand<Commands::GENERATE, Algorithm::BRUTAL>() {
    
    VolumeType volume_range;
    unsigned int objects_number, copies_number;

    //read parameters
    std::cin >> objects_number >> copies_number >> volume_range;

    TestModule::run<Algorithm::BRUTAL>(objects_number, copies_number, volume_range);
}

template<> void CommandInterpreter::runCommand<Commands::GENERATE, Algorithm::DYNAMIC>() {
    
    VolumeType volume_range;
    unsigned int objects_number, copies_number;

    //read parameters
    std::cin >> objects_number >> copies_number >> volume_range;

    TestModule::run<Algorithm::DYNAMIC>(objects_number, copies_number, volume_range);
}

template<> void CommandInterpreter::runCommand<Commands::TEST, Algorithm::BRUTAL>() {

    TestModule test_module = TestModule();
    test_module.runBatch<Algorithm::BRUTAL>();
}

template<> void CommandInterpreter::runCommand<Commands::TEST, Algorithm::DYNAMIC>() {

    TestModule test_module = TestModule();
    test_module.runBatch<Algorithm::DYNAMIC>();
}

void CommandInterpreter::interprete (std::string command, std::string algorithm) {
    //run apprioprate command
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