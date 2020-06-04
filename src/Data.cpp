/**
 * @file Data.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Data class implementation.
 * 
 */

#include "Data.h"

using namespace Knapsack;

const ValueType Data::MAX_VALUE_TYPE = FLT_MAX;

Data::Data(): volume_(0), object_count_(0), max_copies_(0) {};

Data::Data(const Data& other): volume_(other.volume_), object_count_(other.object_count_),
max_copies_(other.max_copies_), objects_(other.objects_) {};

Data::Data(Data&& other): volume_(std::move(other.volume_)), object_count_(std::move(other.object_count_)),
max_copies_(std::move(other.max_copies_)), objects_(std::move(other.objects_)) {};

Data::~Data() {};

Data Data::operator=(const Data& other) {
    volume_ = other.volume_;
    object_count_ = other.object_count_;
    max_copies_ = other.max_copies_;
    objects_ = other.objects_;
    return *this;
}

Data Data::operator=(Data&& other) {
    volume_ = std::move(other.volume_);
    object_count_ = std::move(other.object_count_);
    max_copies_ = std::move(other.max_copies_);
    objects_ = std::move(other.objects_);
    return *this;
}

std::ostream& Knapsack::operator<<(std::ostream& os, const Data& data) {
    os << "C: " << data.getVolume() << "\tm: " << data.getMaxCopies() << "\tn: " << data.getObjectCount() << "\npi: \tci: \n";

    std::for_each(data.getObjectsConst().begin(), data.getObjectsConst().end(), [&](const ObjectValues& object){ os << object.first << "\t" << object.second; });

    return os;
}

void Knapsack::printBasicData(std::ostream& os, const Data& data) {
    os << "C: " << data.getVolume() << "\tm: " << data.getMaxCopies() << "\tn: " << data.getObjectCount() << "\n";
}

void Data::setVolume(VolumeType volume) {
    volume_ = volume;
}

void Data::setObjectCount(unsigned int count) {
    object_count_ = count;
}

void Data::setMaxCopies(unsigned int count) {
    max_copies_ = count;
}

void Data::setObjects(const ObjectContainer& objects) {
    objects_ = objects;
    object_count_ = objects_.size();
}

void Data::addObject(ObjectValues object) {
    objects_.push_back(object);
    ++object_count_;
}

void Data::addObject(ValueType value, VolumeType volume) {
    objects_.emplace_back(value, volume);
    ++object_count_;
}

bool Data::isValid() const {

    if(volume_<1 || object_count_<1 || max_copies_<1 || object_count_!=objects_.size()) return false;

    for (const ObjectValues& object : objects_) { 
        if(object.second<1) return false;
    }

    return true;
}

const VolumeType& Data::getVolume() const {
    return volume_;
}

const unsigned int& Data::getObjectCount() const {
    return object_count_;
}

const unsigned int& Data::getMaxCopies() const {
    return max_copies_;
}

ObjectContainer& Data::getObjects() {
    return objects_;
}

const ObjectContainer& Data::getObjectsConst() const {
    return objects_;
}

ObjectValues& Data::getObject(int index){
    return objects_.at(index);
}

const ObjectValues& Data::getObjectConst(int index) const {
    return objects_.at(index);
}

void Data::clear() {
    volume_ = 0;
    object_count_ = 0;
    max_copies_ = 0;
    objects_.clear();
}