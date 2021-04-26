

#include "gtest/gtest.h"

#include "WritableMappedData.hh"
#include "MapSavableObject.hh"

#include <utility>

static const msd::Key INT_KEY = 123;
static const msd::Key DOUBLE_KEY = 456;
static const msd::Key STR_KEY = 789;

static const int TEST_INT = 12;
static const double TEST_DOUBLE = 27.4;
static const std::string TEST_STR = "Hello world!";

class WritableMappedDataMock: public msd::WritableMappedData{
public:
    WritableMappedDataMock():
        mAddIntegerCallCount{0},
        mAddDoubleCallCount{0},
        mAddStringCopyCallCount{0},
        mAddStringMoveCallCount{0}{
    }


    virtual bool addInteger(msd::Key key, int value){
        return addValue(key, value, mIntKey, mIntValue, mAddIntegerCallCount);
    }
    
    virtual bool addDouble(msd::Key key, double value){
        return addValue(key, value, mDoubleKey, mDoubleValue, mAddDoubleCallCount);
    }

    virtual bool addString(msd::Key key, const std::string& value){
        return addValue(key, value, mStringKey, mStringValue, mAddStringCopyCallCount);
    }

    virtual bool addString(msd::Key key, std::string&& value){
        return addValue(key, std::move(value), mStringKey, mStringValue, mAddStringMoveCallCount);
    }

    std::pair<msd::Key, int> getInteger() const {
        return {mIntKey, mIntValue};
    }

    std::pair<msd::Key, double> getDouble() const {
        return {mDoubleKey, mDoubleValue};
    }

    std::pair<msd::Key, const std::string&> getString() const {
        return {mStringKey, mStringValue};
    }

    int addIntegerCallCount() const{
        return mAddIntegerCallCount;
    };
    int addDoubleCallCount() const{
        return mAddDoubleCallCount;
    };
    int addStringCopyCallCount() const{
        return mAddStringCopyCallCount;
    };
    int addStringMoveCallCount() const{
        return mAddStringMoveCallCount;
    };


private:

    template <typename ValueType>
    bool addValue(msd::Key newKey, const ValueType& newValue, msd::Key& keyToSet, ValueType& valueToSet, int& callCount){
        keyToSet = newKey;
        valueToSet = newValue;
        callCount++;
        return true;
    }

    template <typename ValueType>
    bool addValue(msd::Key newKey, ValueType&& newValue, msd::Key& keyToSet, ValueType& valueToSet, int& callCount){
        keyToSet = newKey;
        valueToSet = std::move(newValue);
        callCount++;
        return true;
    }

    int mAddIntegerCallCount;
    int mAddDoubleCallCount;
    int mAddStringCopyCallCount;
    int mAddStringMoveCallCount;

    msd::Key mIntKey;
    msd::Key mDoubleKey;
    msd::Key mStringKey;
    int mIntValue;
    double mDoubleValue;
    std::string mStringValue;

};


class PersonData: public msd::MapSavableObject{
public:
    PersonData(const std::string& name, int age, double weight):
    m_name{name}, m_age{age}, m_weight{weight}{}
    virtual bool convert(msd::WritableMappedData& mappedData) const{
        mappedData.add(STR_KEY, m_name);
        mappedData.add(INT_KEY, m_age);
        mappedData.add(DOUBLE_KEY, m_weight);
        return true;
    }
private:
    std::string m_name;
    int m_age;
    double m_weight;
};

TEST(MapSavableObject, convert) {
    auto mockWMD = WritableMappedDataMock{};
    auto personData = PersonData{TEST_STR, TEST_INT, TEST_DOUBLE};


    auto intExpectedValue = std::make_pair(INT_KEY, TEST_INT);
    auto doubleExpectedValue = std::make_pair(DOUBLE_KEY, TEST_DOUBLE);
    
    auto intNumCallsBefore = mockWMD.addIntegerCallCount();
    auto doubleNumCallsBefore = mockWMD.addDoubleCallCount();
    auto stringNumCallsBefore = mockWMD.addStringCopyCallCount();


    personData.convert(mockWMD);

    auto intNumCallsAfter = mockWMD.addIntegerCallCount();
    auto doubleNumCallsAfter = mockWMD.addDoubleCallCount();
    auto stringNumCallsAfter = mockWMD.addStringCopyCallCount();
    
    ASSERT_EQ(intExpectedValue, mockWMD.getInteger());
    ASSERT_EQ(doubleExpectedValue, mockWMD.getDouble());

    auto pairStringResult = mockWMD.getString();
    ASSERT_EQ(STR_KEY, std::get<0>(pairStringResult));
    ASSERT_EQ(TEST_STR, std::get<1>(pairStringResult));

    ASSERT_EQ(intNumCallsBefore+1,intNumCallsAfter);
    ASSERT_EQ(doubleNumCallsBefore+1,doubleNumCallsAfter);
    ASSERT_EQ(stringNumCallsBefore+1,stringNumCallsAfter);
}