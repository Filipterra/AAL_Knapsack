/**
 * @file TestDataGenerator.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestDataGenerator class implementation.
 * 
 */

#include "TestDataGenerator.h"

using namespace Knapsack;

DataPointer TestDataGenerator::generate(int object_count, int max_copies, VolumeType volume_range, int instance, int instance_count) {

    DataPointer data = std::make_shared<Data>();
    
    data->setMaxCopies(max_copies);

    srand(time(NULL));

    ValueType value = 0;
    VolumeType volume = 0, volume_sum = 0; 
    for (int i=0; i< object_count; ++i)
    {
        volume = (rand() % volume_range) + 1;
        value = volume + volume_range/10;

        data->addObject(value, volume);

        volume_sum += volume * max_copies;
    }

    data->setVolume( (instance/(instance_count+1) ) * volume_sum);

    return data;
}