/**
 * @file TestModule.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. TestModule for knapsack algorithm class implementation.
 * 
 */


#include "TestModule.h"

using namespace Knapsack;

    TestModule::TestModule(std::initializer_list<unsigned int> object_numbers = {50, 100, 200, 500, 1000, 2000}, 
    std::initializer_list<unsigned int> max_copy_numbers = {2, 3, 5}, std::initializer_list<VolumeType> volume_ranges = {1000, 10000}) {
        object_numbers_ = object_numbers;
        max_copy_numbers_ = max_copy_numbers;
        volume_ranges_ = volume_ranges;
    }

    TestModule::TestModule(TestModule& other): object_numbers_(other.object_numbers_),
    max_copy_numbers_(other.max_copy_numbers_), volume_ranges_(other.volume_ranges_) {}

    TestModule::TestModule(TestModule&& other): object_numbers_(std::move(other.object_numbers_)),
    max_copy_numbers_(std::move(other.max_copy_numbers_)), volume_ranges_(std::move(other.volume_ranges_)) {}

    TestModule::~TestModule() {};

    TestModule TestModule::operator=(const TestModule& other) {
        object_numbers_ = other.object_numbers_;
        max_copy_numbers_ = other.max_copy_numbers_;
        volume_ranges_ = other.volume_ranges_;
        return *this;
    }

    TestModule TestModule::operator=(TestModule&& other) {
        object_numbers_ = std::move(other.object_numbers_);
        max_copy_numbers_ = std::move(other.max_copy_numbers_);
        volume_ranges_ = std::move(other.volume_ranges_);
        return *this;
    }

    std::vector<unsigned int>& TestModule::getObjectNumbers() {
        return object_numbers_;
    }

    const std::vector<unsigned int>& TestModule::getObjectNumbers() const {
        return object_numbers_;
    }

    std::vector<unsigned int>& TestModule::getMaxCopyNumbers() {
        return max_copy_numbers_;
    }

    const std::vector<unsigned int>& TestModule::getMaxCopyNumbers() const {
        return max_copy_numbers_;
    }

    std::vector<unsigned int>& TestModule::getVolumeRanges() {
        return volume_ranges_;
    }

    const std::vector<unsigned int>& TestModule::getVolumeRanges() const {
        return volume_ranges_;
    }

    void TestModule::setObjectNumbers(std::initializer_list<unsigned int> object_numbers) {
        object_numbers_ = object_numbers;
    }

    void TestModule::setMaxCopyNumbers(std::initializer_list<unsigned int> max_copy_numbers) {
        max_copy_numbers_ = max_copy_numbers;
    }

    void TestModule::setVolumeRanges(std::initializer_list<VolumeType> volume_ranges) {
        volume_ranges_ = volume_ranges;
    }

    void TestModule::addObjectNumber(unsigned int object_number) {
        object_numbers_.push_back(object_number);
        std::sort(object_numbers_.begin(), object_numbers_.end());
    }

    void TestModule::addMaxCopyNumber(unsigned int max_copy_number) {
        max_copy_numbers_.push_back(max_copy_number);
        std::sort(max_copy_numbers_.begin(), max_copy_numbers_.end());
    }

    void TestModule::addVolumeRange(VolumeType volume_range) {
        volume_ranges_.push_back(volume_range);
        std::sort(volume_ranges_.begin(), volume_ranges_.end());
    }

    void TestModule::run(int object_count, int max_copies, VolumeType volume_range) {

    }

    void TestModule::runBatch(int instance_count) {

    }