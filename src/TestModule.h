/**
 * @file TestModule.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestModule for knapsack algorithm class header.
 * 
 */

#ifndef KNAPSACK_TEST_MODULE_H
#define KNAPSACK_TEST_MODULE_H

#include <chrono>
#include <iostream>
#include <cmath>
#include "TestDataGenerator.h"
#include "Brutal.h"
#include "Dynamic.h"

namespace Knapsack {

    /**
     * @brief Algorithm types
     * 
     */
    enum class Algorithm { DYNAMIC, BRUTAL };

    /**
     * @brief Class for testing Knapsack problem algorithms
     * 
     */
    class TestModule {
    private:

        /**
         * @brief object counts to test in batch
         * 
         */
        std::vector<unsigned int> object_numbers_;

        /**
         * @brief max copy numbers to test in batch
         * 
         */
        std::vector<unsigned int> max_copy_numbers_;

        /**
         * @brief volume ranges to test in batch
         * 
         */
        std::vector<VolumeType> volume_ranges_;

    public:

    /**
     * @brief Construct a new TestModule object with given test parameters
     * 
     */
    TestModule(std::initializer_list<unsigned int> object_numbers = {5, 10, 15, 20}, 
    std::initializer_list<unsigned int> max_copy_numbers = {2, 3}, std::initializer_list<VolumeType> volume_ranges = {1000, 10000});

    /**
     * @brief Construct a new TestModule object copying from another
     * 
     * @param other object to copy
     */
    TestModule(const TestModule& other);

    /**
     * @brief Construct a new TestModule object moving from another
     * 
     * @param other object to move
     */
    TestModule(TestModule&& other);

    /**
     * @brief Destroy the TestModule object
     * 
     */
    ~TestModule();

    /**
    * @brief Copying assigment operator
    * 
    * @param other object to copy
    * @return TestModule object with copied values
    */
    TestModule operator=(const TestModule& other);

    /**
    * @brief Moving assigment operator
    * 
    * @param other object to move
    * @return TestModule object with moved values
    */
    TestModule operator=(TestModule&& other);

    /**
     * @brief Get the Object Numbers vector
     * 
     * @return std::vector<unsigned int>& 
     */
    std::vector<unsigned int>& getObjectNumbers();

    /**
     * @brief Get the constant Object Numbers vector
     * 
     * @return const std::vector<unsigned int>& 
     */
    const std::vector<unsigned int>& getObjectNumbers() const;

    /**
     * @brief Get the Max Copy Numbers vector
     * 
     * @return std::vector<unsigned int>& 
     */
    std::vector<unsigned int>& getMaxCopyNumbers();

    /**
     * @brief Get the constant Max Copy Numbers vector
     * 
     * @return const std::vector<unsigned int>& 
     */
    const std::vector<unsigned int>& getMaxCopyNumbers() const;

    /**
     * @brief Get the Volume Ranges vector
     * 
     * @return std::vector<unsigned int>& 
     */
    std::vector<unsigned int>& getVolumeRanges();

    /**
     * @brief Get the constant Volume Ranges vector
     * 
     * @return const std::vector<unsigned int>& 
     */
    const std::vector<unsigned int>& getVolumeRanges() const;

    /**
     * @brief Set the Object Numbers object
     * 
     * @param object_numbers list of object numbers
     */
    void setObjectNumbers(std::initializer_list<unsigned int> object_numbers);

    /**
     * @brief Set the Max Copy Numbers object
     * 
     * @param max_copy_numbers list of max copy numbers
     */
    void setMaxCopyNumbers(std::initializer_list<unsigned int> max_copy_numbers);

    /**
     * @brief Set the Volume Ranges object
     * 
     * @param volume_ranges list of ranges
     */
    void setVolumeRanges(std::initializer_list<VolumeType> volume_ranges);

    /**
     * @brief add object number to test and sort
     * 
     * @param object_number new number to test
     */
    void addObjectNumber(unsigned int object_number);

    /**
     * @brief add max copy number to test and sort
     * 
     * @param max_copy_number new number to test
     */
    void addMaxCopyNumber(unsigned int max_copy_number);

    /**
     * @brief add range to test and sort
     * 
     * @param volume_range new range to test
     */
    void addVolumeRange(VolumeType volume_range);

    /**
     * @brief Generate data, run one test, measure time and print results.
     * 
     * @tparam Algorithm choose solving algorithm
     * @param object_count number of objects to be generated
     * @param max_copies max number of copies of each object
     * @param volume_range range for volume randomization
     */
    template <Algorithm algorithm = Algorithm::DYNAMIC> static void run(unsigned int object_count, unsigned int max_copies, VolumeType volume_range);

    /**
     * @brief Run one test, measure time and print results.
     * 
     * @tparam Algorithm choose solving algorithm
     * @param data problem data
     */
    template <Algorithm algorithm = Algorithm::DYNAMIC> static void run(DataPointer data);

    /**
     * @brief Run tests for each combination of hold values instance_count times, measure mean time and print results.
     * 
     * @tparam Algorithm choose solving algorithm
     * @param instance_count number of times each test is repeated with different data
     */
    template <Algorithm algorithm = Algorithm::DYNAMIC> void runBatch(unsigned int instance_count = 10);

    /**
     * @brief helper function for calculating teoretical complexity of the brutal algorithm
     * 
     * @param objects number of objects
     * @param max_copies maximum number of copies of each object
     * @return long long long long value for comparison
     */
    inline long long teoreticBrutal(unsigned int objects, unsigned int max_copies);

    /**
     * @brief helper function for calculating teoretical complexity of the dynamic algorithm
     * 
     * @param objects number of objects
     * @param volume volume of knapsack
     * @return long long value for comparison
     */
    inline long long teoreticDynamic(unsigned int objects, VolumeType volume);
    
    };

}

#endif