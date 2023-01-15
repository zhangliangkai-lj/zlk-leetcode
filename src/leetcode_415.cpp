//
// Created by zlk on 1/15/23.
//
#include <gtest/gtest.h>
#include <algorithm>

class Solution {
 public:
  std::string addStrings(const std::string &n1, const std::string &n2) {
    int carry = 0;
    std::string res;
    for (int i = n1.size() - 1, j = n2.size() - 1; i >= 0 || j >= 0; --i, --j) {
      int b1 = 0;
      if (i >= 0) {
        b1 = n1[i] - '0';
      }
      int b2 = 0;
      if (j >= 0) {
        b2 = n2[j] - '0';
      }
      int sum = b1 + b2 + carry;
      char c = sum % 10 + '0';
      carry = sum / 10;
      res.push_back(c);
    }
    if (carry) {
      res.push_back('1');
    }
    std::reverse(res.begin(), res.end());
    return res;
  }
};

TEST(leetcode, 415) {
  std::string n1 = "123";
  std::string n2 = "45";
  std::string expect = "168";
  ASSERT_EQ(Solution().addStrings(n1, n2), expect);
}