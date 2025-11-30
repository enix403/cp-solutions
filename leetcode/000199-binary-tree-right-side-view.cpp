#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &s, pair<A, B> t) {
  return s << "(" << t.first << "," << t.second << ")";
}

#define output(ty)                                                             \
  template <typename... Ts>                                                    \
  std::ostream &operator<<(std::ostream &s, const ty<Ts...> &t) {              \
    for (const auto &x : t)                                                    \
      s << x << " ";                                                           \
    return s;                                                                  \
  }
output(vector);
output(set);
output(unordered_set);
output(multiset);
output(unordered_multiset);
output(map);
output(unordered_map);
#undef output

#define bit(x, i) (x & (1 << i))
#define abs(x) (x < 0 ? (-x) : x)
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename K, typename V> using uset = unordered_map<K, V>;

#define pb push_back
#define fi first
#define se second

template <typename T> //
using max_heap = priority_queue<T>;
template <typename T> //
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  using Node = TreeNode*;
  vector<int> rightSideView(TreeNode *root) {
    if (!root)
      return {};

    umap<int, int> mp;
    int maxl = 0;
    stack<pair<Node, int>> st;

    st.push({root, 0});

    while (st.size()) {
      Node node = st.top().fi;
      int level = st.top().se;
      st.pop();

      if (!node)
        continue;

      if (mp.count(level) == 0) {
        mp[level] = node->val;
        maxl = max(maxl, level);
      }

      // order matters, left must be pushed first
      st.emplace(node->left, level + 1);
      st.emplace(node->right, level + 1);
    }

    vi res(maxl + 1);

    for (int i = 0; i <= maxl; ++i)
      res[i] = mp[i];

    return res;
  }
};

// int main() {}
