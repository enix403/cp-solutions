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
  int minCostConnectPoints(vector<vector<int>>& points)
  {
    int n = points.size();
    vvi dst(n, vi(n, 0));

    for (int i = 0; i < n; ++i) {
      const auto& pi = points[i];
      for (int j = i + 1; j < n; ++j) {
        const auto& pj = points[j];

        int d = abs(pi[0] - pj[0]) + abs(pi[1] - pj[1]);
        dst[i][j] = d;
        dst[j][i] = d;
      }
    }

    /// prims algorithm
    vb vis(n, false);
    // {w,v}
    min_heap<pii> q;
    q.push({0, 0});

    int res = 0;

    while (q.size()) {
      auto [wt, v] = q.top();
      q.pop();

      if (vis[v])
        continue;

      vis[v] = true;
      res += wt;

      for (int i = 0; i < n; ++i) {
        if (i == v)
          continue;

        if (vis[i])
          continue;

        q.push({dst[i][v], i});
      }
    }

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // vvi points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
  vvi points = {{3,12},{-2,5},{-4,1}};
  Solution s;

  s.minCostConnectPoints(points);

  return 0;
}
