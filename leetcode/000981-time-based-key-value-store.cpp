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
class TimeMap
{
  unordered_map<string, vector<pair<int, string>>> m;

public:
  TimeMap() {}

  void set(string key, string value, int timestamp)
  {
    m[key].emplace_back(timestamp, std::move(value));
  }

  string get(string key, int timestamp)
  {
    if (!m.count(key))
      return "";

    const auto& values = m[key];

    if (values.size() == 0)
      return "";

    int l = 0;
    int r = values.size() - 1;

    int res = -1;

    while (l <= r) {
      int m = (l + r) / 2;
      int t = values[m].first;

      if (t <= timestamp) {
        res = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }

    if (res == -1)
      return "";

    return values[res].second;
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // Solution s;

  return 0;
}
