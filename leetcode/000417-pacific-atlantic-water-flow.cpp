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

// ----------------


const v<pii> dirs = {
  { 0,  1},
  { 0, -1},
  { 1,  0},
  {-1,  0}
};

class Solution
{
public:
  const int UNVISITED = 0;
  const int ATLANTIC = 0b01;
  const int PACIFIC = 0b10;
  const int BOTH = ATLANTIC | PACIFIC;

  vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid)
  {
    const int R = grid.size();
    const int C = grid[0].size();

    auto inside = [&](int r, int c) -> bool {
      return r >= 0 && r < R && c >= 0 && c < C;
    };

    // cells that are visited by both Atlantic's and Pacific's edges
    vvi res;
    vvi mark(R, vi(C, UNVISITED));

    auto dfs = [&](auto&& self, int r, int c, int m, int val) {
      if (mark[r][c] & m)
        return;

      mark[r][c] |= m;

      if (mark[r][c] == BOTH) {
        res.push_back({r,c});
      }

      for (auto [dr, dc] : dirs) {
        int x = r + dr;
        int y = c + dc;

        if (!inside(x, y))
          continue;

        if (mark[x][y] & m)
          continue;

        int newval = grid[x][y];
        if (newval >= val) {
          self(self, x, y, m, newval);
        }
      }
    };

    const int L = R + C - 1;

    // move in L-shaped path around perimeter
    for (int i = 0, r = R - 1, c = 0; i < L; ++i) {
      int x = r;
      int y = c;
      dfs(dfs, x, y, ATLANTIC, grid[x][y]);

      x = R - r - 1;
      y = C - c - 1;
      dfs(dfs, x, y, PACIFIC, grid[x][y]);

      if (c < C - 1)
        c++;
      else
        r--;
    }

    return res;
  }
};

/*
-----------

  | 0 1 2 3 4
--|----------
0 | 1 2 2 3 5
1 | 3 2 3 4 4
2 | 2 4 5 3 1
3 | 6 7 1 4 5
4 | 5 1 1 2 4

------

*/

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vvi grid = {
      {1, 2, 2, 3, 5},
      {3, 2, 3, 4, 4},
      {2, 4, 5, 3, 1},
      {6, 7, 1, 4, 5},
      {5, 1, 1, 2, 4}
  };
  cout << Solution().pacificAtlantic(grid) << endl;

  return 0;
}
