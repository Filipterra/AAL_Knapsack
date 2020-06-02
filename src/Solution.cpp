/**
 * @file Solution.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Solution class implementation.
 * 
 */

#include "Solution.h"

using namespace Knapsack;

Solution::Solution(): value_(0), used_volume_(0) {};

Solution::Solution(Solution& other): value_(other.value_), used_volume_(other.used_volume_),
data_(other.data_), used_copies_(other.used_copies_) {};

Solution::Solution(Solution&& other): value_(std::move(other.value_)), used_volume_(std::move(other.used_volume_)),
data_(std::move(other.data_)), used_copies_(std::move(other.used_copies_)) {};

Solution::Solution(DataPointer data): value_(0), used_volume_(0), data_(data) {
    used_copies_.resize(data_->getObjectCount(), 0);
};

Solution::~Solution() {};

Solution Solution::operator=(const Solution& other) {
    value_ = other.value_;
    used_volume_ = other.used_volume_;
    data_ = other.data_;
    used_copies_ = other.used_copies_;
    return *this;
}

Solution Solution::operator=(Solution&& other) {
    value_ = std::move(other.value_);
    used_volume_ = std::move(other.used_volume_);
    data_ = std::move(other.data_);
    used_copies_ = std::move(other.used_copies_);
    return *this;
}

void Solution::setValue (ValueType value) {
    value_ = value;
}

void Solution::setVolume (VolumeType volume) {
    used_volume_ = volume;
}

void Solution::setData (DataPointer data) {
    data_ = data;
}

void Solution::setUsedCopies (std::vector<unsigned int>& used_copies) {
    used_copies_ = used_copies;
}

ValueType Solution::getValue() {
    return value_;
}

VolumeType Solution::getVolume() {
    return used_volume_;
}

DataPointer Solution::getData() {
    return data_;
}

std::vector<unsigned int>& Solution::getUsedCopies() {
    return used_copies_;
}

void Solution::clear() {
    value_ = 0;
    used_volume_ = 0;
    data_ = nullptr;
    used_copies_.clear();
}

void Solution::calculateValues() {
    if(!isDataValid()) throw std::invalid_argument("Not solved.");

    value_ = 0;
    used_volume_ = 0;

    for (int i=0; i<used_copies_.size(); ++i)
    {
        value_ += data_->getObject(i).first * used_copies_[i];
        used_volume_ += data_->getObject(i).second * used_copies_[i];
    }
}

bool Solution::isDataValid() {
    if (!data_->isValid() || data_->getObjectCount()!=used_copies_.size()) return false;

    for (unsigned int& copies : used_copies_) {
        if(copies>data_->getMaxCopies()) return false;
    }

    return true;
}

bool Solution::isValid() {
    if (used_volume_<1 || !isDataValid()) return false;
    return true;
}

void Solution::addCopy(int index) {
    ++used_copies_.at(index);
    value_ += data_->getObjectConst(index).first;
    used_volume_ += data_->getObjectConst(index).second;
}