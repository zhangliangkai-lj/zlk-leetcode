//
// Created by zlk on 1/28/23.
//

#include <gtest/gtest.h>
#include <algorithm>

class Solution {
 public:
  std::string shortestPalindrome(const std::string &s) {
    const int kBase = 131;
    // hash = last hash * kBase + t
    using ull = unsigned long long;
    ull mul = 1;
    ull prefixHash = 0;
    ull suffixHash = 0;
    int idx = 0;
    auto sz = s.size();
    for (int i = 0; i < sz; ++i) {
      int val = s[i] - 'a' + 1;
      prefixHash = prefixHash * kBase + val;
      suffixHash = suffixHash + mul * val;
      mul *= kBase;
      // 前缀hash和后缀hash相等
      if (prefixHash == suffixHash) {
        idx = i + 1;
      }
    }
    if (idx == sz) {
      return s;
    }
    auto prefix = s.substr(idx, sz - idx);
    std::reverse(prefix.begin(), prefix.end());
    return prefix + s;
  }
};

TEST(leetcode, 214) {
  auto s = "aacecaaa";
  std::string expect = "aaacecaaa";
  auto res = Solution().shortestPalindrome(s);
  ASSERT_EQ(res, expect);
}
