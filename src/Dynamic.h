/**
 * @file Dynamic.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Dynamic knapsack algorithm class header.
 * 
 */

#ifndef KNAPSACK_DYNAMIC_H
#define KNAPSACK_DYNAMIC_H

#include "Solution.h"

namespace Knapsack {

    /**
     * @brief Class for Dynamic solution of the Knapsack problem
     * 
     */
    class Dynamic {
    private:

        /**
         * @brief Solution for last run problem
         * 
         */
        Solution solution_;

    public:

    /**
     * @brief Construct a new Dynamic object
     * 
     */
    Dynamic();

    /**
     * @brief Construct a new Dynamic object copying from another
     * 
     * @param other object to copy
     */
    Dynamic(const Dynamic& other);

    /**
     * @brief Construct a new Dynamic object moving from another
     * 
     * @param other object to move
     */
    Dynamic(Dynamic&& other);

    /**
     * @brief Destroy the Dynamic object
     * 
     */
    ~Dynamic();

    /**
    * @brief Copying assigment operator
    * 
    * @param other object to copy
    * @return Dynamic object with copied values
    */
    Dynamic operator=(const Dynamic& other);

    /**
    * @brief Moving assigment operator
    * 
    * @param other object to move
    * @return Dynamic object with moved values
    */
    Dynamic operator=(Dynamic&& other);

    /**
     * @brief Get the const Solution object
     * 
     * @return const Solution& last found solution
     */
    const Solution& getSolution();

    /**
     * @brief Dynamic Knapsack solving algorithm
     * 
     * @param data data for the problem
     * @return const Solution& found solution
     */
    const Solution& run(DataPointer data);
    
    };

}

#endif