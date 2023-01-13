//
// Created by zlk on 1/13/23.
//

#include <gtest/gtest.h>

class Solution {
  int searchTarget(const std::vector<int> &nums, int target) {
    int low = 0;
    int high = nums.size();
    while (low < high) {
      int mid = (high - low) / 2 + low;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    return -1;
  }

 public:
  std::vector<int> searchRange(const std::vector<int> &nums, int target) {
    auto index = searchTarget(nums, target);
    if (index == -1) {
      return {-1, -1};
    }
    int low = index - 1;
    while (low >= 0 && nums[low] == target)--low;
    int high = index + 1;
    while (high < nums.size() && nums[high] == target) ++high;
    return {low + 1, high - 1};
  }
};

TEST(leetcode, 34) {
  std::vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  std::vector<int> expect = {3, 4};
  auto res = Solution().searchRange(nums, target);
  EXPECT_EQ(res[0], expect[0]);
  EXPECT_EQ(res[1], expect[1]);
}