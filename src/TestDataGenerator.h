/**
 * @file TestDataGenerator.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestDataGenerator class header.
 * 
 */

#ifndef KNAPSACK_TEST_DATA_GENERATOR_H
#define KNAPSACK_TEST_DATA_GENERATOR_H

#include <ctime>
#include "Data.h"

namespace Knapsack {

    /**
     * @brief Class generating problem data. Not for usage as an object. Just for static methods.
     * 
     */
    class TestDataGenerator {
    private:

    public:

        TestDataGenerator() = delete;

        TestDataGenerator(const TestDataGenerator& other) = delete;

        TestDataGenerator(TestDataGenerator&& other) = delete;

        ~TestDataGenerator() = delete;

        TestDataGenerator operator=(const TestDataGenerator& other) = delete;

        TestDataGenerator operator=(TestDataGenerator&& other) = delete;

        /**
         * @brief Generate new problem data with given parameters. Rest of the values derive from those.
         * 
         * @param object_count number of objects in problem
         * @param max_copies maximum number of copies of each object that can be used in the solution
         * @param volume_range maximum value of volume of an object
         * @param instance test data instance number
         * @param instance_count number of test data instances beeing generated in this batch
         * @return DataPointer pointer to generated problem data
         */
        static DataPointer generate(int object_count, int max_copies, VolumeType volume_range, unsigned int instance, unsigned int instance_count);

    };

}

#endif