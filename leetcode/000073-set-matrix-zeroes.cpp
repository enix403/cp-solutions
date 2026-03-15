// clang++ -std=c++17 -DCUSTOM_DEBUG main.cpp && ./a.out

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
// start copy from here

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

//
typedef vector<int> vi;
typedef vector<vi> vvi;
//
typedef vector<ll> vl;
typedef vector<vl> vvl;
//
typedef vector<bool> vb;
typedef vector<vb> vvb;
//
typedef pair<int, int> pii;
typedef vector<pii> vii;
//
typedef pair<ll, ll> pll;
// clang-format off
template <typename T> using v = vector<T>;
template <typename T> using vv = vector<vector<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T> using uset = unordered_set<T>;
// clang-format on

const v<pii> DIRS = {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

// ----------------

const int INF = 1e9;

class Solution
{
public:
  void setZeroes(vector<vector<int>>& matrix)
  {
    const int R = matrix.size();
    const int C = matrix[0].size();

    vi rz(R, 1);
    vi cz(C, 1);

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        int v = bool(matrix[r][c]);
        rz[r] *= v;
        cz[c] *= v;
      }
    }

    for (int r = 0; r < R; ++r) {
      for (int c = 0; c < C; ++c) {
        if (rz[r] == 0 || cz[c] == 0)
          matrix[r][c] = 0;
      }
    }
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;
  return 0;
}
