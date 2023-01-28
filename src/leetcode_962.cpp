//
// Created by zlk on 1/28/23.
//

#include <gtest/gtest.h>
#include <stack>
#include <algorithm>

class Solution {
 public:
  int maxWidthRamp(const std::vector<int> &nums) {
    int res = 0;
    std::stack<int> st;
    auto sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      while (st.empty() || nums[i] < nums[st.top()]) {
        st.push(i);
      }
    }
    for (int i = sz - 1; i >= 0; --i) {
      while (!st.empty() && nums[st.top()] <= nums[i]) {
        res = std::max(res, i - st.top());
        st.pop();
      }
    }
    return res;
  }
};

TEST(leetcode, 962) {
  std::vector<int> nums = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
  int expect = 7;
  ASSERT_EQ(Solution().maxWidthRamp(nums), expect);
}