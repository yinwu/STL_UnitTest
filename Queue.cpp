#include "gtest/gtest.h"
#include <queue>

TEST(queue, construction_v1) {
    std::queue<int> q;

    EXPECT_EQ(0, q.size());
}

TEST(queue, push_front_back_size) {
    std::queue<int> q;
    q.push(100);
    EXPECT_EQ(1, q.size());
    EXPECT_EQ(100, q.front());
    EXPECT_EQ(100, q.back());

    q.push(200);

    EXPECT_EQ(2, q.size());
    EXPECT_EQ(100, q.front());
    EXPECT_EQ(200, q.back());

    q.pop();
    EXPECT_EQ(1, q.size());
    EXPECT_EQ(200, q.front());
    EXPECT_EQ(200, q.back());
}

TEST(queue, emplace) {
    std::queue<std::string> q;
    q.emplace("hello");
    q.emplace("world");

    EXPECT_EQ(2, q.size());
    EXPECT_EQ("hello", q.front());
    EXPECT_EQ("world", q.back());

    q.pop();

    EXPECT_EQ(1, q.size());
    EXPECT_EQ("world", q.front());
    EXPECT_EQ("world", q.back());

}