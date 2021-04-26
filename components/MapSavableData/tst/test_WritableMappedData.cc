

#include "gtest/gtest.h"

#include "WritableMappedData.hh"

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

TEST(WritableMappedData, setInteger) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(INT_KEY, TEST_INT);
    auto numCallsBefore = mock.addIntegerCallCount();
    auto added = mock.addInteger(INT_KEY, TEST_INT);

    auto numCallsAfter = mock.addIntegerCallCount();
    
    ASSERT_TRUE(added);
    ASSERT_EQ(expectedValue, mock.getInteger());
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setIntegerGenericAdd) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(INT_KEY, TEST_INT);
    auto numCallsBefore = mock.addIntegerCallCount();
    auto added = mock.add(INT_KEY, TEST_INT);

    auto numCallsAfter = mock.addIntegerCallCount();
    
    ASSERT_TRUE(added);
    ASSERT_EQ(expectedValue, mock.getInteger());
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setDouble) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(DOUBLE_KEY, TEST_DOUBLE);
    auto numCallsBefore = mock.addDoubleCallCount();

    auto added = mock.addDouble(DOUBLE_KEY, TEST_DOUBLE);
    
    auto numCallsAfter = mock.addDoubleCallCount();
    ASSERT_TRUE(added);
    ASSERT_EQ(expectedValue, mock.getDouble());
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setDoubleGeneric) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(DOUBLE_KEY, TEST_DOUBLE);
    auto numCallsBefore = mock.addDoubleCallCount();

    auto added = mock.add(DOUBLE_KEY, TEST_DOUBLE);
    
    auto numCallsAfter = mock.addDoubleCallCount();
    ASSERT_TRUE(added);
    ASSERT_EQ(expectedValue, mock.getDouble());
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setStringCopy) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(STR_KEY, TEST_STR);
    auto numCallsBefore = mock.addStringCopyCallCount();

    auto added = mock.addString(STR_KEY, TEST_STR);
    
    auto numCallsAfter = mock.addStringCopyCallCount();
    ASSERT_TRUE(added);
    auto strPair = mock.getString();
    ASSERT_EQ(std::get<0>(expectedValue), std::get<0>(strPair));
    ASSERT_EQ(std::get<1>(expectedValue), std::get<1>(strPair));
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setStringCopyGenericAdd) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(STR_KEY, TEST_STR);
    auto numCallsBefore = mock.addStringCopyCallCount();

    auto added = mock.add(STR_KEY, TEST_STR);
    
    auto numCallsAfter = mock.addStringCopyCallCount();
    ASSERT_TRUE(added);
    auto strPair = mock.getString();
    ASSERT_EQ(std::get<0>(expectedValue), std::get<0>(strPair));
    ASSERT_EQ(std::get<1>(expectedValue), std::get<1>(strPair));
    ASSERT_EQ(numCallsBefore+1,numCallsAfter);
}

TEST(WritableMappedData, setStringMove) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(STR_KEY, TEST_STR);
    auto numCallsBefore = mock.addStringMoveCallCount();

    auto added = mock.addString(STR_KEY, "Hello world!");
    
    auto numCallsAfter = mock.addStringMoveCallCount();
    ASSERT_TRUE(added);
    auto strPair = mock.getString();
    ASSERT_EQ(std::get<0>(expectedValue), std::get<0>(strPair));
    ASSERT_EQ(std::get<1>(expectedValue), std::get<1>(strPair));
    ASSERT_EQ(numCallsBefore+1, numCallsAfter);
}

TEST(WritableMappedData, setStringMoveGenericAdd) {
    auto mock = WritableMappedDataMock{};
    auto expectedValue = std::make_pair(STR_KEY, TEST_STR);
    auto numCallsBefore = mock.addStringMoveCallCount();

    auto added = mock.add(STR_KEY, "Hello world!");
    
    auto numCallsAfter = mock.addStringMoveCallCount();
    ASSERT_TRUE(added);
    auto strPair = mock.getString();
    ASSERT_EQ(std::get<0>(expectedValue), std::get<0>(strPair));
    ASSERT_EQ(std::get<1>(expectedValue), std::get<1>(strPair));
    ASSERT_EQ(numCallsBefore+1, numCallsAfter);
}

