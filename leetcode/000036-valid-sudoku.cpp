#include <cstdint>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

using Mask = uint16_t;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    Mask rows[9]{0};
    Mask cols[9]{0};
    Mask blocks[9]{0};

    for (int r = 0, br = 0; r < 9; ++r) {
      if (r && r % 3 == 0)
        br += 3;
      for (int c = 0, bc = 0; c < 9; ++c) {
        if (c && c % 3 == 0)
          bc++;
        if (board[r][c] != '.') {
          int v = board[r][c] - '0';
          int m = 1 << v;
          int b = br + bc;
          if (rows[r] & m || cols[c] & m || blocks[b] & m)
            return false;
          rows[r] |= m;
          cols[c] |= m;
          blocks[b] |= m;
        }
      }
    }
    return true;
  }
};
