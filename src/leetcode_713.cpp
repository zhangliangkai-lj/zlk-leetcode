//
// Created by zlk on 1/16/23.
//

#include <gtest/gtest.h>

class Solution {
 public:
  int numSubarrayProductLessThanK(const std::vector<int> &nums, int k) {
    if (k < 2) {
      return 0;
    }
    long product = 1;
    auto sz = nums.size();
    int low = 0;
    int high = 0;
    while (product < k && high < sz) {
      product *= nums[high++];
    }
    int res = 0;
    while (low < sz) {
      res += high - low;
      if (product >= k) {
        --res;
      }
      product /= nums[low++];
      while (product < k && high < sz) {
        product *= nums[high++];
      }
    }
    return res;
  }
};

TEST(leetcode, 713) {
  std::vector<int> nums = {10, 5, 2, 6};
  int k = 100;
  ASSERT_EQ(Solution().numSubarrayProductLessThanK(nums, k), 8);
}