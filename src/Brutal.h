/**
 * @file Brutal.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Brutal knapsack algorithm class header.
 * 
 */

#ifndef KNAPSACK_BRUTAL_H
#define KNAPSACK_BRUTAL_H

#include "Solution.h"
#include "Data.h"

namespace Knapsack {

    /**
     * @brief Class for brutal solution of the Knapsack problem
     * 
     */
    class Brutal {
    private:

        /**
         * @brief Solution for last run problem
         * 
         */
        Solution solution_;

    /**
     * @brief Recursive generation of variations of number of used objects and saving best found solution in solution_. Used in Brutal::run. Doesn't check parameters validity.
     * 
     * @param position Should start with object_count-1. Is decremented in recursion and serves as the stop condition.
     * @param value Should start with 0. Locally updated and provided to next recursion.
     * @param volume Should start with 0. Locally updated and provided to next recursion. Also serves as early stop condition.
     * @param object_count Should start with number of objects. Shared between recursions.
     * @param max_copies Should start with max number of copies of each object it's allowed to use. Shared between recursions.
     * @param max_value Should start with minimal possible value of ValueType. Shared between recursions. Updated when better solution is found.
     * @param solution Should start with vector of size = object_count filled with 0's. Shared between recursions. Updated when better solution is found.
     */
    void generateVariation (int position, ValueType value, int volume, const int& object_count, const int& max_copies, ValueType& max_value, std::vector<unsigned int>& solution);

    public:

    /**
     * @brief Construct a new Brutal object
     * 
     */
    Brutal();

    /**
     * @brief Construct a new Brutal object copying from another
     * 
     * @param other object to copy
     */
    Brutal(const Brutal& other);

    /**
     * @brief Construct a new Brutal object moving from another
     * 
     * @param other object to move
     */
    Brutal(Brutal&& other);

    /**
     * @brief Destroy the Brutal object
     * 
     */
    ~Brutal();

    /**
    * @brief Copying assigment operator
    * 
    * @param other object to copy
    * @return Brutal object with copied values
    */
    Brutal operator=(const Brutal& other);

    /**
    * @brief Moving assigment operator
    * 
    * @param other object to move
    * @return Brutal object with moved values
    */
    Brutal operator=(Brutal&& other);

    /**
     * @brief Get the const Solution object
     * 
     * @return const Solution& last found solution
     */
    const Solution& getSolution();

    /**
     * @brief Brutal Knapsack solving algorithm
     * 
     * @param data data for the problem
     * @return const Solution& found solution
     */
    const Solution& run(DataPointer data) throw(std::invalid_argument);
    
    };

}

#endif