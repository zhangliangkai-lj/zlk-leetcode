//
// Created by zlk on 1/13/23.
//
#include <gtest/gtest.h>

class Solution {
 public:
  int chalkReplacer(const std::vector<int> &chalk, int k) {
    std::vector<long> sums = {0};
    for (auto &&n: chalk) {
      sums.push_back(n + sums.back());
    }
    k = k % sums.back();
    for (int i = 0; i < sums.size(); ++i) {
      if (sums[i] > k) {
        return i - 1;
      }
    }
    return 0;
  }
};

TEST(leetcode, 1894) {
  std::vector<int> chalk = {3, 4, 1, 2};
  int k = 25;
  int expect = 1;
  EXPECT_EQ(Solution().chalkReplacer(chalk, k), expect);
}

