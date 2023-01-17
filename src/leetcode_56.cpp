//
// Created by zlk on 1/17/23.
//
#include <gtest/gtest.h>
#include <algorithm>

class Solution {
  using Range = std::vector<int>;
 public:
  std::vector<Range> merge(std::vector<Range> &matrix) {
    if (matrix.empty()) {
      return {};
    }
    std::sort(matrix.begin(), matrix.end(), [](const Range &r1, const Range &r2) {
      if (r1[0] == r2[0]) {
        return r1[1] < r2[1];
      }
      return r1[0] < r2[0];
    });
    std::vector<Range> res;
    int low = matrix[0][0];
    int high = matrix[0][1];
    for (int i = 1; i < matrix.size(); ++i) {
      if (matrix[i][0] <= high) {
        high = std::max(matrix[i][1], high);
      } else {
        res.push_back({low, high});
        low = matrix[i][0];
        high = matrix[i][1];
      }
    }
    res.push_back({low, high});
    return res;
  }
};

TEST(leetcode, 56) {
  std::vector<std::vector<int>> matrix = {
      {1, 3}, {2, 6}, {8, 10}, {15, 18}
  };
  auto res = Solution().merge(matrix);
  decltype(res) expect = {
      {1, 6}, {8, 10}, {15, 18}
  };
  ASSERT_EQ(res.size(), expect.size());
  for (int i = 0; i < res.size(); ++i) {
    ASSERT_EQ(res[i].size(), expect[i].size());
    for (int j = 0; j < res[i].size(); ++j) {
      ASSERT_EQ(res[i][j], expect[i][j]);
    }
  }
}
