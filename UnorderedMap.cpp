#include "gtest/gtest.h"
#include <unordered_map>

TEST(unordered_map, construction) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    std::map<int, int> map = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};

    EXPECT_EQ(1, map.begin()->first);
    EXPECT_EQ(11, map.begin()->second);

    EXPECT_EQ(5, umap.begin()->first);
    EXPECT_EQ(55, umap.begin()->second);
}


TEST(unordered_map, forward_iterator) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    auto it = umap.begin();
    it++;
    //it--; for unordered_map, there is no -- operator.
}

TEST(unordered_map, bucket_count) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.bucket_count(), 7);
}

TEST(unordered_map, max_bucket_count) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.max_bucket_count(), 357913941);
}

TEST(unordered_map, bucket_size) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.bucket_size(0), 0);
    EXPECT_EQ(umap.bucket_size(1), 1);
}

TEST(unordered_map, bucket) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.bucket(5), 5);
    EXPECT_EQ(umap.bucket(1), 1);
    EXPECT_EQ(umap.bucket(2), 2);
    EXPECT_EQ(umap.bucket(3), 3);
    EXPECT_EQ(umap.bucket(4), 4);
}

TEST(unordered_map, load_factor) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.load_factor(), (float)5/7);
}

TEST(unordered_map, max_load_factor) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.max_load_factor(), 1.0);
}

TEST(unordered_map, reserve) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.bucket_count(), 7);
    EXPECT_EQ(umap.load_factor(), (float)5/7);
    umap.reserve(20);
    EXPECT_EQ(umap.bucket_count(), 23);
    EXPECT_EQ(umap.load_factor(), (float)5/23);
}

TEST(unordered_map, rehash) {
    std::unordered_map<int, int> umap = {{2, 22}, {3, 33}, {1, 11}, {4, 44}, {5, 55}};
    EXPECT_EQ(umap.bucket_count(), 7);
    EXPECT_EQ(umap.load_factor(), (float)5/7);
    EXPECT_EQ(umap.bucket(5), 5);
    umap.rehash(20);
    EXPECT_EQ(umap.bucket_count(), 23);
    EXPECT_EQ(umap.bucket(5), 5);
    EXPECT_EQ(umap.load_factor(), (float)5/23);
}