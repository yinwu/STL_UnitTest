#include <gtest/gtest.h>
#include <deque>

TEST(deque, construction) {
    std::deque<int> dq = {1,2,3,4,5};

    EXPECT_EQ(dq.size(), 5);
    EXPECT_FALSE(dq.empty());
}

TEST(deque, max_size) {
    std::deque<int> dq = {1,2,3,4,5};

    EXPECT_EQ(dq.max_size(), 1073741823);
}

TEST(deque, resize) {
    std::deque<int> dq = {1,2,3,4,5};

    EXPECT_EQ(dq.size(), 5);

    dq.resize(10, 100);

    EXPECT_EQ(dq.size(), 10);

    dq.resize(7);

    EXPECT_EQ(dq.size(), 7);
}

TEST(deque, shrink_to_fit) {
    std::deque<int> dq(100);

    EXPECT_EQ(dq.size(), 100);

    dq.resize(10);

    dq.shrink_to_fit();
    EXPECT_EQ(dq.size(), 10);
}

TEST(deque, push_and_pop) {
    std::deque<int> dq(100, 55);

    dq.push_back(999);
    dq.push_front(111);
    EXPECT_EQ(111, dq.front());
    EXPECT_EQ(999, dq.back());

    EXPECT_EQ(dq.size(), 102);

    dq.pop_front();

    EXPECT_EQ(55, dq.front());
    EXPECT_EQ(999, dq.back());
    EXPECT_EQ(dq.size(), 101);

    dq.pop_back();

    EXPECT_EQ(55, dq.front());
    EXPECT_EQ(55, dq.back());
    EXPECT_EQ(dq.size(), 100);
}


TEST(deque, insert) {
    std::deque<int> dq(100, 55);

    auto it = dq.begin();
    it++;

    dq.insert(it, 3, 44);

    EXPECT_EQ(103, dq.size());

    EXPECT_EQ(55, dq.front());

    dq.pop_front();

    EXPECT_EQ(44, dq.front());
}


TEST(deque, erase) {
    std::deque<int> dq(100, 55);

    auto it = dq.begin();
    it++;

    dq.erase(it);

    EXPECT_EQ(99, dq.size());

    EXPECT_EQ(55, dq.front());
}

TEST(deque, random_access) {
    std::deque<int> dq;

    for(int i = 0; i < 10; i++) {
        dq.push_back(i);
    }

    for(int i = 0; i < 10; i++) {
        EXPECT_EQ(dq[i], i);
    }
}