//
// Created by zlk on 1/16/23.
//

#include <gtest/gtest.h>
#include <unordered_map>

class Solution {
 public:
  int lengthOfLongestSubstring(const std::string &s) {
    auto sz = s.size();
    if (sz < 2) {
      return sz;
    }
    int res = 1;
    std::unordered_map<char, int> charPos;
    int curPos = 0;
    for (int i = 0; i < sz; ++i) {
      if (charPos.find(s[i]) != charPos.end()) {
        res = std::max(res, i - std::max(charPos[s[i]], curPos - 1));
        curPos = std::max(charPos[s[i]] + 1, curPos);
      } else {
        res = std::max(res, i - curPos + 1);
      }
      charPos[s[i]] = i;
    }
    return res;
  }
};

TEST(leetcode, 3) {
  auto s = "aabaab!bb";
  int expect = 3;
  ASSERT_EQ(Solution().lengthOfLongestSubstring(s), expect);
}