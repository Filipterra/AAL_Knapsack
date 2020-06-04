/**
 * @file Brutal.cpp
 * @author Przybsz Filip
 * 
 * @brief Knapsack. Brutal knapsack algorithm class implementation.
 * 
 */

#include "Brutal.h"

using namespace Knapsack;

Brutal::Brutal() {
    solution_.setValue(0);
    solution_.setVolume(0);
    solution_.setData(nullptr);
};

Brutal::Brutal(const Brutal& other): solution_(other.solution_) {};

Brutal::Brutal(Brutal&& other): solution_(std::move(other.solution_)) {};

Brutal::~Brutal() {};

Brutal Brutal::operator=(const Brutal& other) {
    solution_ = other.solution_;
    return *this;
}

Brutal Brutal::operator=(Brutal&& other) {
    solution_ = std::move(other.solution_);
    return *this;
}

const Solution& Brutal::getSolution() {
    return solution_;
}

void Brutal::generateVariation (int position, ValueType value, int volume, const int& object_count, const int& max_copies, ValueType& max_value, std::vector<unsigned int>& solution) {
    //Go through all possible used copies number for this object
    for (int i=0; i<=max_copies; ++i)
    {
        //Set used copies for this object
        solution[position] = i;

        //Update local value and volume with values of used object
        if(i>0)
        {
            value += solution_.getData()->getObjectConst(position).first;
            volume += solution_.getData()->getObjectConst(position).second;
        }
        
        //Early end to this branch of recursion
        if (volume>solution_.getData()->getVolume())
        {   
            break;
        }
            

        //Continue generating
        if (position!=0)
        {
            generateVariation(position - 1, value, volume, object_count, max_copies, max_value, solution);
        }
        //Last position
        else
        {
            //Check if found solution is better than the last
            if (value > max_value)
            {
                max_value = value;
                solution_.setUsedCopies(solution);
                solution_.setValue(value);
                solution_.setVolume(volume);
            }
                
        }
        
    }

}

const Solution& Brutal::run(DataPointer data) {
    //check data validity
    if(!data->isValid()) throw std::invalid_argument("Wrong algorithm arguments.");

    //clear last solution
    solution_.clear();

    //prepare data for recursion
    solution_.getUsedCopies().resize(data->getObjectCount(), 0);
    solution_.setData(data);
    ValueType max_value = -Data::MAX_VALUE_TYPE;
    
    //run recursion generating variations and saving best found solutions
    generateVariation (data->getObjectCount() - 1, 0, 0, data->getObjectCount(), data->getMaxCopies(), max_value, solution_.getUsedCopies());

    return solution_;
}