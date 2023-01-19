//
// Created by zlk on 1/19/23.
//

#include <gtest/gtest.h>
#include <deque>

class Solution {
 public:
  std::vector<int> maxSlidingWindow(const std::vector<int> &nums, int k) {
    std::vector<int> res;
    std::deque<int> que;
    int sz = nums.size();
    for (int i = 0; i < k && i < sz; ++i) {
      while (!que.empty() && nums[i] > nums[que.back()]) {
        que.pop_back();
      }
      que.push_back(i);
    }
    for (int i = k; i < sz; ++i) {
      res.push_back(nums[que.front()]);
      while (!que.empty() && i - que.front() >= k) {
        que.pop_front();
      }
      while (!que.empty() && nums[i] > nums[que.back()]) {
        que.pop_back();
      }
      que.push_back(i);
    }
    res.push_back(nums[que.front()]);
    return res;
  }
};

TEST(leetcode, 239) {
  std::vector<int> nums = {1, 3, 1, 2, 0, 5};
  int k = 3;
  std::vector<int> expect = {3, 3, 2, 5};
  auto res = Solution().maxSlidingWindow(nums, k);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}
