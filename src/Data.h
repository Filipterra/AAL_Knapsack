/**
 * @file Data.h
 * @author Przybysz Filip
 * 
 * @brief Knapsack. Data class header.
 * 
 */

#include <vector>

/**
 * @brief Namespace for Knapsack project objects
 * 
 */
namespace Knapsack {

    using ValueType = float;
    using VolumeType = int;

    /**
     * @brief Pair type of object value and volume
     * 
     */
    using ObjectValues = std::pair<ValueType,VolumeType>;

    using ObjectContainer = std::vector<ObjectValues>;

    /**
     * @brief Class containing problem data
     * 
     */
    class Data {
    private:
        /**
         * @brief Container volume
         * 
         */
        VolumeType volume_;

        /**
         * @brief Number of objects
         * 
         */
        int object_count_;

        /**
         * @brief Number of times the same object can be used
         * 
         */
        int max_copies_;

        /**
         * @brief Container for objects
         * 
         */
        ObjectContainer objects_;

    public:

        /**
         * @brief Construct a new Data object
         * 
         */
        Data();

        /**
         * @brief Construct a new Data object by copying another
         * 
         * @param other object to copy
         */
        Data(const Data& other);

        /**
         * @brief Construct a new Data object by moving another
         * 
         * @param other object to move
         */
        Data(Data&& other);

        /**
         * @brief Destroy the Data object
         * 
         */
        ~Data();

        /**
         * @brief Copying assigment operator
         * 
         * @param other object to copy
         * @return Data object with copied values
         */
        Data operator=(const Data& other);

        /**
         * @brief Moving assigment operator
         * 
         * @param other object to move
         * @return Data object with moved values
         */
        Data operator=(Data&& other);

        /**
         * @brief Set the Volume value
         * 
         * @param volume new volume
         */
        void setVolume(VolumeType volume);

        /**
         * @brief Set the Object Count value
         * 
         * @param count new object count
         */
        void setObjectCount(int count);

        /**
         * @brief Set the Max Copies value
         * 
         * @param count new max copies
         */
        void setMaxCopies(int count);

        /**
         * @brief Set the Objects container and object count
         * 
         * @param objects new objects container
         */
        void setObjects(const ObjectContainer& objects);

        /**
         * @brief Add new object of ObjectValues type to container and increment object count
         * 
         * @param object new object
         */
        void addObject(ObjectValues object);

        /**
         * @brief Add new object with given value and volume to container and increment object count
         * 
         * @param value value of new object
         * @param volume volume of new object
         */
        void addObject(ValueType value, VolumeType volume);

        /**
         * @brief Check data validity
         * 
         * @return true if valid
         * @return false if not valid
         */
        bool isValid() const;

        /**
         * @brief Get the Volume value
         * 
         * @return const VolumeType& 
         */
        const VolumeType& getVolume() const;


        /**
         * @brief Get the Object Count value
         * 
         * @return const int& 
         */
        const int& getObjectCount() const;

        /**
         * @brief Get the Max Copies value
         * 
         * @return const int& 
         */
        const int& getMaxCopies() const;

        /**
         * @brief Get the Objects container for modyfication
         * 
         * @return ObjectContainer& 
         */
        ObjectContainer& getObjects() const;

        /**
         * @brief Get the constant Objects container
         * 
         * @return const ObjectContainer& 
         */
        const ObjectContainer& getObjectsConst() const;

        /**
         * @brief Get the object from given index in container for modyfication
         * 
         * @param index index of the object
         * @return ObjectValues& object reference
         */
        ObjectValues& getObject(int index) const;

        /**
         * @brief Get the constant object from given index in container
         * 
         * @param index index of the object
         * @return const ObjectValues& constant object reference
         */
        const ObjectValues& getObjectConst(int index) const;

    };

}