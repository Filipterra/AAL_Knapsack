/**
 * @file Solution.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Solution class header.
 * 
 */

#ifndef KNAPSACK_SOLUTION_H
#define KNAPSACK_SOLUTION_H

#include <memory>
#include <stdexcept>
#include "Data.h"

namespace Knapsack {

    using DataPointer = std::shared_ptr<Data>;

    /**
     * @brief Solution class
     * 
     */
    class Solution {
    private:
        /**
         * @brief reached value
         * 
         */
        ValueType value_;

        /**
         * @brief used volume
         * 
         */
        VolumeType used_volume_;

        /**
         * @brief problem data
         * 
         */
        DataPointer data_;

        /**
         * @brief number of objects used
         * 
         */
        std::vector<unsigned int> used_copies_;

        /**
         * @brief check if data and used copies are valid
         * 
         * @return true is valid
         * @return false is not valid
         */
        bool isDataValid();

    public:

        /**
         * @brief Construct a new Solution object
         * 
         */
        Solution();

        /**
         * @brief Construct a new Solution object by copying another
         * 
         * @param other object to copy
         */
        Solution(Solution& other);

        /**
         * @brief Construct a new Solution object by moving another
         * 
         * @param other object to move
         */
        Solution(Solution&& other);

        /**
         * @brief Construct a new Solution object with given problem data
         * 
         * @param data 
         */
        Solution(DataPointer data);

        /**
         * @brief Destroy the Solution object
         * 
         */
        ~Solution();

        /**
         * @brief Copying assigment operator
         * 
         * @param other object to copy
         * @return Solution object with copied values
         */
        Solution operator=(const Solution& other);

        /**
         * @brief Moving assigment operator
         * 
         * @param other object to move
         * @return Solution object with moved values
         */
        Solution operator=(Solution&& other);

        /**
         * @brief Set the reached value
         * 
         * @param value new reached value
         */
        void setValue (ValueType value);

        /**
         * @brief Set the used volume
         * 
         * @param volume new used volume
         */
        void setVolume (VolumeType volume);

        /**
         * @brief Set the problem data
         * 
         * @param data new problem data
         */
        void setData (DataPointer data);

        /**
         * @brief Set the Used Copies vector
         * 
         * @param used_copies new used copies
         */
        void setUsedCopies (std::vector<unsigned int>& used_copies);

        /**
         * @brief Get the reached value
         * 
         * @return ValueType reached value
         */
        ValueType getValue();

        /**
         * @brief Get the used volume
         * 
         * @return VolumeType used volume
         */
        VolumeType getVolume();

        /**
         * @brief Get the problem data
         * 
         * @return DataPointer problem data
         */
        DataPointer getData();

        /**
         * @brief Get the Used Copies vector
         * 
         * @return std::vector<unsigned int>& Used Copies vector
         */
        std::vector<unsigned int>& getUsedCopies();

        /**
         * @brief clear solution data
         * 
         */
        void clear();

        /**
         * @brief calculate and set value and used volume based on problem data and used copies
         * 
         */
        void calculateValues() throw(std::invalid_argument);

        /**
         * @brief check if solution is valid
         * 
         * @return true is valid
         * @return false is not valid
         */
        bool isValid();

        /**
         * @brief Update value, volume and used copies as if the object of given index from data objects was added to the solution. Doesn't check constraints.
         * 
         */
        void addCopy(int index);
    };

}

#endif