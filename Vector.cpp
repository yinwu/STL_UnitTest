#include <vector>
#include "gtest/gtest.h"


using namespace std;

TEST(vector, size) {
    std::vector<int> v = {1};
    ASSERT_EQ(v.size(), 1);
}