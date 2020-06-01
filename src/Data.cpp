/**
 * @file Data.cpp
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Data class implementation.
 * 
 */

#include "Data.h"

using namespace Knapsack;

Data::Data(): volume_(-1), object_count_(0), max_copies_(-1) {};

Data::Data(const Data& other): volume_(other.volume_), object_count_(other.object_count_),
max_copies_(other.max_copies_), objects_(other.objects_) {};

Data::Data(Data&& other): volume_(std::move(other.volume_)), object_count_(std::move(other.object_count_)),
max_copies_(std::move(other.max_copies_)), objects_(std::move(other.objects_)) {};

Data::~Data() {};

Data Data::operator=(const Data& other) {
    volume_=other.volume_;
    object_count_=other.object_count_;
    max_copies_=other.max_copies_;
    objects_=other.objects_;
}

Data Data::operator=(Data&& other) {
    volume_=std::move(other.volume_);
    object_count_=std::move(other.object_count_);
    max_copies_=std::move(other.max_copies_);
    objects_=std::move(other.objects_);
}

void Data::setVolume(VolumeType volume) {
    volume_=volume;
}

void Data::setObjectCount(int count) {
    object_count_=count;
}

void Data::setMaxCopies(int count) {
    max_copies_=count;
}

void Data::setObjects(const ObjectContainer& objects) {
//TODO:
}

void Data::addObject(ObjectValues object) {
//TODO:
}