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

struct DSU
{
  vi par;

  DSU(int n)
  {
    par.assign(n, 0);
    for (int i = 0; i < n; ++i)
      par[i] = i;
  }

  int find_set(int x)
  {
    if (x == par[x])
      return x;
    return par[x] = find_set(par[x]);
  }

  void merge(int a, int b)
  {
    a = find_set(a);
    b = find_set(b);
    if (a != b)  // if they are already not merged
      par[b] = a;
  }
};

class Solution
{
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();
    DSU d(n);

    for (const auto& ed: edges) {
      int a = ed[0];
      int b = ed[1];
      a--;
      b--;

      int sa = d.find_set(a);
      int sb = d.find_set(b);

      if (sa == sb) {
        return {a+1, b+1};
      }

      d.merge(a, b);
    }

    return {};
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // vvi edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
  vvi edges = {{1,2},{1,3},{2,3}};
  cout << Solution().findRedundantConnection(edges) << endl;

  return 0;
}
