#include <algorithm>

TEST(algorithm, min) {
    EXPECT_EQ(4, std::min(4, 6));
}

TEST(algorithm, max) {
    EXPECT_EQ(6, std::min(4, 6));
}
