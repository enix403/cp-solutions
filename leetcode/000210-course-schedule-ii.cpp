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
  vector<int> findOrder(int n, vector<vector<int>>& prerequisites)
  {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);

    for (auto& e : prerequisites) {
      int a = e[0];
      int b = e[1];
      adj[b].push_back(a);
      indeg[a]++;
    }

    queue<int> q;

    for (int i = 0; i < n; ++i)
      if (indeg[i] == 0)
        q.push(i);

    vector<int> res;
    while (q.size()) {
      int src = q.front();
      q.pop();
      res.push_back(src);
      // src has no incoming edges
      for (int d : adj[src]) {
        if (--indeg[d] == 0)
          q.push(d);
      }
    }

    if (res.size() != n)
      res.clear();

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  return 0;
}
