//
// Created by zlk on 1/14/23.
//

#include <gtest/gtest.h>

class Solution {
  std::vector<int> mergeSort(std::vector<int> &left, std::vector<int> &right) {
    std::vector<int> res;
    int i = 0;
    int j = 0;
    while (i < left.size() || j < right.size()) {
      if (j == right.size() || (i < left.size() && left[i] <= right[j])) {
        res.push_back(left[i++]);
      } else {
        res.push_back(right[j++]);
      }
    }
    return res;
  }
 public:
  std::vector<int> sortArray(std::vector<int> &nums) {
    auto sz = nums.size();
    if (sz < 2) {
      return nums;
    }
    auto left = std::vector<int>(nums.begin(), nums.begin() + sz / 2);
    auto sortedLeft = sortArray(left);
    auto right = std::vector<int>(nums.begin() + sz / 2, nums.end());
    auto sortedRight = sortArray(right);
    return mergeSort(sortedLeft, sortedRight);
  }
};

TEST(leetcode, 912) {
  std::vector<int> nums = {5, 2, 3, 1};
  auto res = Solution().sortArray(nums);
  decltype(nums) expect = {1, 2, 3, 5};
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}