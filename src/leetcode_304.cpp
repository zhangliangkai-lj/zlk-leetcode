//
// Created by zlk on 1/15/23.
//

#include <gtest/gtest.h>

class NumMatrix {
  std::vector<std::vector<int>> sums_;
 public:
  NumMatrix(const std::vector<std::vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    sums_ = std::vector<std::vector<int>>(row + 1, std::vector<int>(col + 1, 0));
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        sums_[i + 1][j + 1] = sums_[i + 1][j] + sums_[i][j + 1] - sums_[i][j] + matrix[i][j];
      }
    }
  }
  int sumRegion(int row1, int col1, int row2, int col2) {
    return (sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1]) - (sums_[row1][col2 + 1] - sums_[row1][col1]);
  }
};

TEST(leetcode, 304) {
  std::vector<std::vector<int>> matrix = {
      {3, 0, 1, 4, 2},
      {5, 6, 3, 2, 1},
      {1, 2, 0, 1, 5},
      {4, 1, 0, 1, 7},
      {1, 0, 3, 0, 5}
  };
  NumMatrix num_matrix(matrix);
  ASSERT_EQ(num_matrix.sumRegion(2, 1, 4, 3), 8);
}