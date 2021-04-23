#include "gtest/gtest.h"

#include "MapReadableObject.hh"

static const msd::Key INT_KEY = 123;
static const msd::Key DOUBLE_KEY = 456;
static const msd::Key STR_KEY = 789;

static const int TEST_INT = 12;
static const double TEST_DOUBLE = 27.4;
static const std::string TEST_STR = "Hello world!";

class MapReadableObjectMock: public msd::MapReadableObject{
public:
    opt::OptInteger getInteger(msd::Key key) const{
        if(key == INT_KEY){
            return {TEST_INT};
        }else{
            return {};
        }
    }
    opt::OptDouble  getDouble(msd::Key key) const{
        if(key == DOUBLE_KEY){
            return {TEST_DOUBLE};
        }else{
            return {};
        }
    }
    opt::OptString  getString(msd::Key key) const{
        if(key == STR_KEY){
            return {TEST_STR};
        }else{
            return {};
        }
    }
};

TEST(MapReadableObject, getIntegerSuccess) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getInteger(INT_KEY);
    ASSERT_TRUE(optValue.isValid());
    ASSERT_EQ(TEST_INT, optValue.value());
}

TEST(MapReadableObject, getIntegerFailure) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getInteger(DOUBLE_KEY);
    ASSERT_FALSE(optValue.isValid());
}

TEST(MapReadableObject, getDoubleSuccess) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getDouble(DOUBLE_KEY);
    ASSERT_TRUE(optValue.isValid());
    ASSERT_EQ(TEST_DOUBLE, optValue.value());
}

TEST(MapReadableObject, getDoubleFailure) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getDouble(STR_KEY);
    ASSERT_FALSE(optValue.isValid());
}

TEST(MapReadableObject, getStringSuccess) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getString(STR_KEY);
    ASSERT_TRUE(optValue.isValid());
    ASSERT_EQ(TEST_STR, optValue.value());
}

TEST(MapReadableObject, getStringFailure) {
    auto mock = MapReadableObjectMock{};
    auto optValue = mock.getString(INT_KEY);
    ASSERT_FALSE(optValue.isValid());
}

