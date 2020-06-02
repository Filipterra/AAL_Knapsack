/**
 * @file TestDataGenerator.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestDataGenerator class header.
 * 
 */

#ifndef KNAPSACK_TEST_DATA_GENERATOR_H
#define KNAPSACK_TEST_DATA_GENERATOR_H

#include "Data.h"

namespace Knapsack {

    /**
     * @brief Class generating problem data
     * 
     */
    class TestDataGenerator {
    private:

    public:

        /**
         * @brief Construct a new TestDataGenerator object
         * 
         */
        TestDataGenerator();

        /**
         * @brief Construct a new TestDataGenerator object by copying another
         * 
         * @param other object to copy
         */
        TestDataGenerator(const TestDataGenerator& other);

        /**
         * @brief Construct a new TestDataGenerator object by moving another
         * 
         * @param other object to move
         */
        TestDataGenerator(TestDataGenerator&& other);

        /**
         * @brief Destroy the TestDataGenerator object
         * 
         */
        ~TestDataGenerator();

        /**
         * @brief Copying assigment operator
         * 
         * @param other object to copy
         * @return TestDataGenerator object with copied values
         */
        TestDataGenerator operator=(const TestDataGenerator& other);

        /**
         * @brief Moving assigment operator
         * 
         * @param other object to move
         * @return TestDataGenerator object with moved values
         */
        TestDataGenerator operator=(TestDataGenerator&& other);

    };

}

#endif