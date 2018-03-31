// https://www.hackerrank.com/challenges/3d-surface-area/problem
// Run `clang++ three-d-surface.cpp && ./a.out`

#include <iostream>
#include <vector>

template <class T> T min(T a, T b) { return a > b ? b : a; }

int surface_area(std::vector<std::vector<int>> &board) {
  int height = board.size();
  int width = board[0].size();
  int area = 2 * width * height; // Start with top- and bottom-surfaces
  for (int row = 0; row < height; row += 1) {
    for (int col = 0; col < width; col += 1) {
      int contribution = 4 * board[row][col];
      if (row > 0) {
        contribution -= min(board[row][col], board[row - 1][col]);
      }
      if (col > 0) {
        contribution -= min(board[row][col], board[row][col - 1]);
      }
      if (row < height - 1) {
        contribution -= min(board[row][col], board[row + 1][col]);
      }
      if (col < width - 1) {
        contribution -= min(board[row][col], board[row][col + 1]);
      }
      area += contribution;
    }
  }
  return area;
}

int main() {
  int width;
  int height;
  std::vector<std::vector<int>> board;
  std::cin >> height >> width;
  for (int i = 0; i < height; i += 1) {
    std::vector<int> next_row;
    for (int j = 0; j < width; j += 1) {
      int next_cell;
      std::cin >> next_cell;
      next_row.push_back(next_cell);
    }
    board.push_back(next_row);
  }

  std::cout << surface_area(board) << std::endl;
  return 0;
}
