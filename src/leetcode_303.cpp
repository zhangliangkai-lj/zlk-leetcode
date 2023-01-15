//
// Created by zlk on 1/15/23.
//

#include <gtest/gtest.h>

class NumArray {
  std::vector<int> sums_;
 public:
  NumArray(const std::vector<int> &nums) {
    sums_.push_back(0);
    for (auto &&n: nums) {
      sums_.push_back(sums_.back() + n);
    }
  }

  int sumRange(int left, int right) {
    return sums_[right + 1] - sums_[left];
  }
};

TEST(leetcode, 303) {

  std::vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray arr(nums);
  EXPECT_EQ(arr.sumRange(0, 2), 1);
}


