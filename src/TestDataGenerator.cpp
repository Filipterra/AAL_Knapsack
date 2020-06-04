/**
 * @file TestDataGenerator.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestDataGenerator class implementation.
 * 
 */

#include "TestDataGenerator.h"
#include <iostream>

using namespace Knapsack;

DataPointer TestDataGenerator::generate(unsigned int object_count, unsigned int max_copies, VolumeType volume_range, unsigned int instance, unsigned int instance_count) {

    DataPointer data = std::make_shared<Data>();
    
    data->setMaxCopies(max_copies);

    srand(time(NULL));

    ValueType value = 0;
    VolumeType volume = 0, volume_sum = 0; 
    //randomize object values
    for (unsigned int i = 0; i < object_count; ++i)
    {
        volume = (rand() % volume_range) + 1; //random volume
        value = volume + volume_range/10; //value strongly correlated with volume

        data->addObject(value, volume);

        volume_sum += volume * max_copies;
    }

    //knapsack volume calculated based on sum of volumes and number of data instances generated in batch
    data->setVolume( (static_cast<double>(instance) / static_cast<double>((instance_count+1))) * volume_sum);

    return data;
}