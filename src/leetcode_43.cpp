//
// Created by zlk on 1/15/23.
//
#include <gtest/gtest.h>
#include <algorithm>

class Solution {
 public:
  std::string multiply(const std::string &n1, const std::string &n2) {
    const std::string kZero = "0";
    if (n1 == kZero || n2 == kZero) {
      return kZero;
    }
    int carry = 0;
    std::string res;
    auto sz1 = n1.size();
    auto sz2 = n2.size();
    res.reserve(sz1 + sz2);
    for (int i = 0; i < sz1 + sz2; ++i) {
      int sum = carry;
      for (int j = 0; j < sz1 && j <= i; ++j) {
        int k = i - j;
        if (k < sz2) {
          sum += (n1[sz1 - 1 - j] - '0') * (n2[sz2 - 1 - k] - '0');
        }
      }
      carry = sum / 10;
      char c = sum % 10 + '0';
      res.push_back(c);
    }
    while (!res.empty() && res.back() == '0') {
      res.pop_back();
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

TEST(leetcode, 43) {
  std::string n1 = "123";
  std::string n2 = "456";
  std::string expect = "56088";
  ASSERT_EQ(Solution().multiply(n1, n2), expect);
}