//
// Created by zlk on 1/13/23.
//
#include <gtest/gtest.h>

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
      n = n & (n - 1);
      ++count;
    }
    return count;
  }
};

TEST(leetcode, 191) {

  uint32_t n = -1;
  int expect = 32;
  EXPECT_EQ(Solution().hammingWeight(n), expect);
}
