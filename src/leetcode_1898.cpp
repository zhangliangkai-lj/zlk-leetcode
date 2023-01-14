//
// Created by zlk on 1/14/23.
//
#include <gtest/gtest.h>
#include <unordered_set>

class Solution {
  bool isSubSeq(const std::string &s, const std::string &p, const std::vector<int> &removable, int k) {
    std::unordered_set<int> indexes;
    for (int i = 0; i < k; ++i) {
      indexes.insert(removable[i]);
    }
    int i = 0;
    int j = 0;
    while (i < s.size() && j < p.size()) {
      if (indexes.find(i) == indexes.end() && s[i] == p[j]) {
        ++j;
      }
      ++i;
    }
    return j == p.size();
  }
 public:
  int maximumRemovals(const std::string &s, const std::string &p, const std::vector<int> &removable) {
    int low = 0;
    int high = removable.size();
    while (low < high) {
      auto mid = (high - low + 1) / 2 + low;
      if (isSubSeq(s, p, removable, mid)) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    return low;
  }
};

TEST(leetcode, 1898) {
  auto s = "abcacb";
  auto p = "ab";
  std::vector<int> removable = {3, 1, 0};
  ASSERT_EQ(Solution().maximumRemovals(s, p, removable), 2);
}