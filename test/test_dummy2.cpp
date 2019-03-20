#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::Return;

class DummyMock {
public:
    MOCK_CONST_METHOD0(method, int());
};

TEST(Dummy2, test) {
    DummyMock mockObj;
    ON_CALL(mockObj, method())
        .WillByDefault(Return(123));
    ASSERT_EQ(123, mockObj.method());
}