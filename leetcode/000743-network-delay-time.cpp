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

const int INF = INT_MAX;

class Solution
{
public:
  int L;
  vv<pii> adj;
  vi d;

  int reached;
  int res;

  void dijsktra(int s)
  {
    reached = 0;
    res = 0;

    // ----

    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;

    min_heap<pii> q;
    q.push({0, s});

    while (q.size()) {
      auto [dv, v] = q.top();
      q.pop();

      if (dv != d[v])
        continue;

      reached++;
      res = max(res, dv);

      for (auto edge : adj[v]) {
        int k = edge.first;
        int cost = edge.second;
        int updated = d[v] + cost;
        if (updated < d[k]) {
          d[k] = updated;
          q.push({d[k], k});
        }
      }
    }
  }

  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    adj.resize(n);
    for (const auto& edge: times) {
      int a = edge[0] - 1;
      int b = edge[1] - 1;
      int cost = edge[2];

      adj[a].push_back({b,cost});
    }

    dijsktra(k-1);

    return reached == n ? res : -1;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vvi times = {{2,1,1},{2,3,1},{3,4,1}};
  int n = 4;
  int k = 2;

  Solution s;

  int res = s.networkDelayTime(times, n, k);

  cout << res << endl;

  return 0;
}
