//
// Created by zlk on 1/28/23.
//

#include <gtest/gtest.h>
#include <stack>

class Solution {
 public:
  std::vector<int> dailyTemperatures(const std::vector<int> &temperatures) {
    auto sz = temperatures.size();
    std::vector<int> res(sz, 0);
    std::stack<int> st;
    for (int i = 0; i < sz; ++i) {
      while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
        res[st.top()] = i - st.top();
        st.pop();
      }
      st.push(i);
    }
    return res;
  }
};

TEST(leetcode, 739) {

  std::vector<int> input = {73, 74, 75, 71, 69, 72, 76, 73};
  std::vector<int> expect = {1, 1, 4, 2, 1, 1, 0, 0};
  auto res = Solution().dailyTemperatures(input);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}