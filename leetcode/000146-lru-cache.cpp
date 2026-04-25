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
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <variant>
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

class LRUCache
{
  using key = int;
  using val = int;

  int rem;
  list<int> access;
  unordered_map<key, pair<val, list<key>::iterator>> mp;

public:
  LRUCache(int capacity) { rem = capacity; }

  int get(key key)
  {
    if (mp.count(key) == 0)
      return -1;

    touch(key);
    return mp[key].first;
  }

  inline void touch(key key)
  {
    // move the key's node at the end
    auto& it = mp[key].second;
    access.erase(it);
    access.push_back(key);
    it = --access.end();
  }

  inline void remove_lru()
  {
    // get the first element in list
    // and delete it
    int key = access.front();
    access.pop_front();
    mp.erase(key);
  }

  void put(int key, int value)
  {
    bool exists = mp.count(key) > 0;
    if (exists) {
      mp[key].first = value;
      touch(key);
      return;
    }

    if (rem == 0) {
      remove_lru();
      rem++;
    }

    access.push_back(key);
    auto it = --access.end();
    mp[key] = {value, it};
    rem--;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // Solution s;

  return 0;
}
