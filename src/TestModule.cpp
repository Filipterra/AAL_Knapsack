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

    TestModule::TestModule(const TestModule& other): object_numbers_(other.object_numbers_),
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

    template<> void TestModule::run<Algorithm::DYNAMIC>(unsigned int object_count, unsigned int max_copies, VolumeType volume_range) {

        auto data = TestDataGenerator::generate(object_count, max_copies, volume_range, 1, 1);
        Dynamic solver = Dynamic();

        auto start_time = std::chrono::steady_clock::now();

        Solution solution = solver.run(data);

        auto end_time = std::chrono::steady_clock::now();
	    auto time_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

        std::cout << "Time: " << time_duration << "\n";
        std::cout << solution;
    }

    template<> void TestModule::run<Algorithm::BRUTAL>(unsigned int object_count, unsigned int max_copies, VolumeType volume_range) {

        auto data = TestDataGenerator::generate(object_count, max_copies, volume_range, 1, 1);
        Brutal solver = Brutal();

        auto start_time = std::chrono::steady_clock::now();

        Solution solution = solver.run(data);

        auto end_time = std::chrono::steady_clock::now();
	    auto time_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

        std::cout << "Time: " << time_duration << "\n";
        std::cout << solution;
    }

    template<> void TestModule::run<Algorithm::DYNAMIC>(DataPointer data) {

        Dynamic solver = Dynamic();

        auto start_time = std::chrono::steady_clock::now();

        Solution solution = solver.run(data);

        auto end_time = std::chrono::steady_clock::now();
	    auto time_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

        std::cout << "Time: " << time_duration << "\n";
        std::cout << solution;
    }

    template<> void TestModule::run<Algorithm::BRUTAL>(DataPointer data) {

        Brutal solver = Brutal();

        auto start_time = std::chrono::steady_clock::now();

        Solution solution = solver.run(data);

        auto end_time = std::chrono::steady_clock::now();
	    auto time_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count();

        std::cout << "Time: " << time_duration << "\n";
        std::cout << solution;
    }

    template<> void TestModule::runBatch<Algorithm::DYNAMIC>(unsigned int instance_count) {
        //TODO: save to file?
        std::sort(object_numbers_.begin(), object_numbers_.end());
        long long mean_time = 0, mean_teoretic_time = 0;
        unsigned int combinations = max_copy_numbers_.size() * volume_ranges_.size();
        std::vector<long long> object_number_mean_time (object_numbers_.size(), 0);
        std::vector<long long> teoretic_object_number_mean_time (object_numbers_.size(), 0);

        Dynamic solver = Dynamic();

        for (unsigned int a = 0; a<object_numbers_.size(); ++a)
        {
            for (unsigned int b = 0; b<max_copy_numbers_.size(); ++b)
                {
                    for (unsigned int c = 0; c<volume_ranges_.size(); ++c)
                        {
                            mean_time = 0;
                            mean_teoretic_time = 0;
                            for (int i=0; i<instance_count; ++i)
                            {
                                auto data = TestDataGenerator::generate(object_numbers_[a], max_copy_numbers_[b], volume_ranges_[c], i, instance_count);
                                auto start_time = std::chrono::steady_clock::now();
                                solver.run(data);
                                auto end_time = std::chrono::steady_clock::now();
                                mean_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / instance_count;
                                mean_teoretic_time += teoreticDynamic(object_numbers_[a], data->getVolume()) / instance_count;
                            }

                            std::cout<< "Objects: " << object_numbers_[a] << "\tCopies: " << max_copy_numbers_[b] << "\tRange: " << volume_ranges_[c] << "\tTime: " << mean_time << "\n";
                        
                            object_number_mean_time[a] += mean_time / combinations;
                            teoretic_object_number_mean_time[a] += mean_teoretic_time / combinations;
                        }
                }
        }

        std::vector<double> estimates;
        //calculate how well the results fit the teoretical assumptions
        for (int i = 0; i<object_numbers_.size(); ++i)
        {
            estimates.push_back( (teoretic_object_number_mean_time[i] * object_number_mean_time[object_numbers_.size() / 2]) /
            (object_number_mean_time[i] * teoretic_object_number_mean_time[object_numbers_.size() / 2]) );
        }

        std::cout<< "\nEstimates:\nn: \tq(n): \n";
        for (int i = 0; i<object_numbers_.size(); ++i)
        {
            std::cout << object_numbers_[i] << "\t" << estimates[i] << "\n";
        }

    }

    template<> void TestModule::runBatch<Algorithm::BRUTAL>(unsigned int instance_count) {
        //TODO: save to file?
        std::sort(object_numbers_.begin(), object_numbers_.end());
        long long mean_time = 0;
        unsigned int combinations = max_copy_numbers_.size() * volume_ranges_.size();
        std::vector<long long> object_number_mean_time (object_numbers_.size(), 0);
        std::vector<long long> teoretic_object_number_mean_time (object_numbers_.size(), 0);
        
        Brutal solver = Brutal();

        for (unsigned int a = 0; a<object_numbers_.size(); ++a)
        {
            for (unsigned int b = 0; b<max_copy_numbers_.size(); ++b)
                {
                    for (unsigned int c = 0; c<volume_ranges_.size(); ++c)
                        {
                            mean_time = 0;

                            for (int i=0; i<instance_count; ++i)
                            {
                                auto data = TestDataGenerator::generate(object_numbers_[a], max_copy_numbers_[b], volume_ranges_[c], i, instance_count);
                                auto start_time = std::chrono::steady_clock::now();
                                solver.run(data);
                                auto end_time = std::chrono::steady_clock::now();
                                mean_time += std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time).count() / instance_count;

                            }

                            std::cout<< "Objects: " << object_numbers_[a] << "\tCopies: " << max_copy_numbers_[b] << "\tRange: " << volume_ranges_[c] << "\tTime: " << mean_time << "\n";

                            object_number_mean_time[a] += mean_time / combinations;
                        }
                    teoretic_object_number_mean_time[a] += teoreticBrutal(object_numbers_[a], max_copy_numbers_[b]) / max_copy_numbers_.size();
                }
        }

        std::vector<double> estimates;
        //calculate how well the results fit the teoretical assumptions
        for (int i = 0; i<object_numbers_.size(); ++i)
        {
            estimates.push_back( (teoretic_object_number_mean_time[i] * object_number_mean_time[object_numbers_.size() / 2]) /
            (object_number_mean_time[i] * teoretic_object_number_mean_time[object_numbers_.size() / 2]) );
        }

        std::cout<< "\nEstimates:\nn: \tq(n): \n";
        for (int i = 0; i<object_numbers_.size(); ++i)
        {
            std::cout << object_numbers_[i] << "\t" << estimates[i] << "\n";
        }
        
    }


    inline long long TestModule::teoreticBrutal(unsigned int objects, unsigned int max_copies) {
        return powl(max_copies + 1, objects);
    }

    inline long long TestModule::teoreticDynamic(unsigned int objects, VolumeType volume) {
        return objects * volume;
    }