//
// Created by zlk on 1/18/23.
//

#include <gtest/gtest.h>

class Solution {
 public:
  int divide(int dividend1, int divisor1) {
    std::map<long, long> divMap;
    long dividend = dividend1;
    long divisor = divisor1;
    bool neg = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0);
    dividend = abs(dividend);
    divisor = abs(divisor);
    if (dividend < divisor) {
      return 0;
    }
    const int kMin = 1 << 31;
    const int kMax = ~kMin;
    long cur = 1;
    long product = divisor;
    while (product <= dividend) {
      divMap[product] = cur;
      cur = (cur << 1);
      product = (product << 1);
    }
    long res = 0;
    for (auto it = divMap.rbegin(); it != divMap.rend(); ++it) {
      while (dividend >= it->first) {
        res += it->second;
        dividend -= it->first;
      }
    }
    if (neg) {
      res = -res;
    }
    if (res > kMax) {
      return kMax;
    }
    if (res < kMin) {
      return kMin;
    }
    return res;
  }
};

TEST(leetcode, 29) {
  ASSERT_EQ(Solution().divide(-2147483648, -1), 2147483647);
}