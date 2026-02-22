#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef CUSTOM_DEBUG
#include "parts/leetcode-tree.h"
#include "parts/printer.h"
#endif

// ----------------

#define bit(x, i) (x & (1 << i))
#define all(c) (c).begin(), (c).end()
#define range2d(r, c, R, C) ((r) >= 0 && (r) < (R) && (c) >= 0 && (c) < (C))

template <typename T>  //
using max_heap = priority_queue<T>;
template <typename T>  //
using min_heap = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
template <typename K, typename V>
using umap = unordered_map<K, V>;
template <typename T>
using uset = unordered_set<T>;
template <typename T>
using v = vector<T>;

// todo generator
const v<pii> DIRS = {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

// ----------------

class Solution
{
public:
  void solve(vector<vector<char>>& board)
  {
    const int R = board.size();
    const int C = board[0].size();

    vvb vis(R, vb(C, false));

    auto dfs = [&](auto& self, int r, int c) {
      if (board[r][c] != 'O')
        return;

      if (vis[r][c])
        return;

      vis[r][c] = true;

      for (auto [dr, dc] : DIRS) {
        int x = r + dr;
        int y = c + dc;

        if (!range2d(x, y, R, C) || vis[x][y] || board[x][y] != 'O')
          continue;

        self(self, x, y);
      }
    };

    for (int r = 0; r < R; ++r) {
      dfs(dfs, r, 0);
      dfs(dfs, r, C - 1);
    }

    for (int c = 1; c < C - 1; ++c) {
      dfs(dfs, 0, c);
      dfs(dfs, R - 1, c);
    }

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (board[r][c] == 'O' && !vis[r][c]) {
          board[r][c] = 'X';
        }
      }
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  v<v<char>> board = {
      {'X', 'X', 'X', 'X'},
      {'X', 'O', 'O', 'X'},
      {'X', 'X', 'O', 'X'},
      {'X', 'O', 'X', 'X'}
  };
  Solution().solve(board);

  for (auto& row: board) {
    cout << row << endl;
  }

  return 0;
}
