/**
 * @file Dynamic.cpp
 * @author Przybsz Filip
 * 
 * @brief Knapsack. Dynamic knapsack algorithm class implementation.
 * 
 */

#include "Dynamic.h"

using namespace Knapsack;

Dynamic::Dynamic() {
    solution_.setValue(0);
    solution_.setVolume(0);
    solution_.setData(nullptr);
};

Dynamic::Dynamic(const Dynamic& other): solution_(other.solution_) {};

Dynamic::Dynamic(Dynamic&& other): solution_(std::move(other.solution_)) {};

Dynamic::~Dynamic() {};

Dynamic Dynamic::operator=(const Dynamic& other) {
    solution_ = other.solution_;
    return *this;
}

Dynamic Dynamic::operator=(Dynamic&& other) {
    solution_ = std::move(other.solution_);
    return *this;
}

const Solution& Dynamic::getSolution() {
    return solution_;
}

const Solution& Dynamic::run(DataPointer data) {
    //check data validity
    if(!data->isValid()) throw std::invalid_argument("Wrong algorithm arguments.");

    //clear last solution
    solution_.clear();

    //prepare data for the algorithm
    solution_.getUsedCopies().resize(data->getObjectCount(), 0);
    solution_.setData(data);
    std::vector<Solution> best_solutions(data->getVolume(), Solution(data));

    //dynamic solution calculation

    //for possible volumes used
    for (int j=1; j<=data->getVolume(); ++j)
    {
            //initialize best solution with best for smaller knapsack
            best_solutions[j]=best_solutions[j-1];

            //check if taking each element would make for a better solution
            for (int i=0; i<data->getObjectCount(); ++i)
            {
                //for clarity
                ValueType i_object_value = data->getObjectConst(i).first;
                VolumeType i_object_volume = data->getObjectConst(i).second;

                //check if element could be used
                if (i_object_volume <= j && best_solutions[j - i_object_volume].getUsedCopies()[i] < data->getMaxCopies())
                {
                    //check if solution would be better
                    if(best_solutions[j - i_object_volume].getValue() + i_object_value > best_solutions[j].getValue())
                    {
                        //create updated solution
                        best_solutions[j] = best_solutions[j - i_object_volume];
                        best_solutions[j].addCopy(i);
                    }
                }
            }
    }


    solution_ = *(best_solutions.end() - 1);

    return solution_;
}