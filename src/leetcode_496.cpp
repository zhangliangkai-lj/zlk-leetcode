//
// Created by zlk on 1/17/23.
//

#include <gtest/gtest.h>
#include <stack>
#include <unordered_map>

class Solution {
 public:
  std::vector<int> nextGreaterElement(const std::vector<int> &n1, const std::vector<int> &n2) {
    std::stack<int> st;
    std::unordered_map<int, int> nextNumber;
    for (auto &n: n2) {
      while (!st.empty() && st.top() < n) {
        nextNumber[st.top()] = n;
        st.pop();
      }
      st.push(n);
    }
    std::vector<int> res;
    for (auto &n: n1) {
      auto it = nextNumber.find(n);
      if (it == nextNumber.end()) {
        res.push_back(-1);
      } else {
        res.push_back(it->second);
      }
    }
    return res;
  }
};

TEST(leetcode, 496) {
  std::vector<int> n2 = {1, 3, 4, 2};
  std::vector<int> n1 = {4, 1, 2};
  std::vector<int> expect = {-1, 3, -1};
  auto res = Solution().nextGreaterElement(n1, n2);
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i], expect[i]);
  }
}