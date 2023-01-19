//
// Created by zlk on 1/19/23.
//


#include <gtest/gtest.h>
#include <queue>

class Solution {
 public:
  int shortestSubarray(const std::vector<int> &nums, int k) {
    int sz = nums.size();
    std::vector<long> sums = {0};
    for (auto &&n: nums) {
      sums.push_back(sums.back() + n);
    }
    std::deque<int> que;
    int res = sz + 1;
    for (int i = 0; i < sz + 1; ++i) {
      while (!que.empty() && sums[i] - sums[que.front()] >= k) {
        res = std::min(res, i - que.front());
        que.pop_front();
      }
      while (!que.empty() && sums[que.back()] >= sums[i]) {
        que.pop_back();
      }
      que.push_back(i);
    }
    return res == sz + 1 ? -1 : res;
  }
};

TEST(leetcode, 862) {
  std::vector<int> nums = {2, -1, 2};
  int k = 3;
  ASSERT_EQ(Solution().shortestSubarray(nums, k), 3);
}