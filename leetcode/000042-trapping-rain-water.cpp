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

template <typename Container, typename Func>
auto map(const Container& c, Func f) {
    std::vector<decltype(f(*c.begin()))> result;
    result.reserve(c.size());
    for (const auto& x : c) result.push_back(f(x));
    return result;
}

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
  int trap(vector<int>& height) {
    int n = height.size();

    vi pref(n, -1); // prefix largest
    vi suf(n, -1); // suffix largest

    int maxi = -1;
    for (int i = 0; i < n; ++i) {
      pref[i] = maxi;

      if (maxi == -1 || height[i] >= height[maxi])
        maxi = i;
    }

    maxi = -1;
    for (int i = n - 1; i >= 0; --i) {
      suf[i] = maxi;

      if (maxi == -1 || height[i] >= height[maxi])
        maxi = i;
    }

    // cout << pref << endl;
    // cout << suf << endl;
    // cout << ::map(pref, [&](int i) { return height[i]; }) << endl;
    // cout << ::map(suf, [&](int i) { return height[i]; }) << endl;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
      int h = height[i];
      int l = pref[i];
      int r = suf[i];

      if (l == -1 || r == -1)
        continue;

      l = height[l];
      r = height[r];

      if (l <= h || r <= h)
        continue;

      res += min(l,r) - h;
    }

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  // vi arr = {0,1,0,2,1,0,1,3,2,1,2,1}; // 6
  // vi arr = {4,2,0,3,2,5}; // 9
  vi arr = {4,2,3}; // 1

  cout << s.trap(arr) << endl;

  return 0;
}
