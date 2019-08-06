#include "gtest/gtest.h"
#include <list>

TEST(list, constuction) {

    std::list<int> l;

    EXPECT_TRUE(l.empty());
}