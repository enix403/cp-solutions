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

class Solution
{
public:
  int maxArea(vector<int>& height)
  {
    int n = height.size();
    int l = 0, r = n - 1;
    int res = 0;
    while (l < r) {
      int hl = height[l];
      int hr = height[r];

      int dx = r - l;

      int val = min(hl, hr) * dx;
      res = max(res, val);

      if (hl < hr)
        l++;
      else
        r--;
    }

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  vi arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  cout << s.maxArea(arr) << endl;

  return 0;
}
