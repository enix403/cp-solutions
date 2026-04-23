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
auto map(const Container& c, Func f)
{
  std::vector<decltype(f(*c.begin()))> result;
  result.reserve(c.size());
  for (const auto& x : c)
    result.push_back(f(x));
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
  const int INF = 10e7 + 2;

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int n = nums1.size();
    int m = nums2.size();
    int total = n + m;
    int half = (total + 1) / 2;

    if (n >= m) {
      nums1.swap(nums2);
      swap(n, m);
    }

    int l = 0;
    int r = n;

    double res = 0;

    while (l <= r) {
      int p1 = (l + r) / 2;
      int p2 = half - p1;

      int e1 = p1 == 0 ? -INF : nums1[p1 - 1];
      int e2 = p2 == 0 ? -INF : nums2[p2 - 1];

      int s1 = p1 == n ? INF : nums1[p1];
      int s2 = p2 == m ? INF : nums2[p2];

      if (e1 <= s2 && e2 <= s1) {
        // cout << e1 << " " << e2 << endl;
        // cout << s1 << " " << s2 << endl;
        if (total % 2)
          // odd
          res = max(e1, e2);
        else
          res = (max(e1, e2) + min(s1, s2)) / 2.0;

        break;
      } else if (e1 > s2) {
        r = p1 - 1;
      } else {
        l = p1 + 1;
      }
    }

    // cout << res << endl;

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // Solution s;

  return 0;
}
