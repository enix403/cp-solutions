#include <algorithm>
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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

TreeNode *buildTree(const std::vector<std::optional<int>> &arr) {
  if (arr.empty() || !arr[0].has_value())
    return nullptr;

  TreeNode *root = new TreeNode(arr[0].value());
  std::queue<TreeNode *> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < arr.size()) {
    TreeNode *cur = q.front();
    q.pop();

    // left child
    if (i < arr.size() && arr[i].has_value()) {
      cur->left = new TreeNode(arr[i].value());
      q.push(cur->left);
    }
    i++;

    // right child
    if (i < arr.size() && arr[i].has_value()) {
      cur->right = new TreeNode(arr[i].value());
      q.push(cur->right);
    }
    i++;
  }
  return root;
}

#define printer_t(ty, expr)                                                    \
  template <typename... Ts>                                                    \
  std::ostream &operator<<(std::ostream &s, const ty<Ts...> &t) {              \
    return s << expr;                                                          \
  }

printer_t(pair, "(" << t.first << "," << t.second << ")");
#undef printer_t

#define printer_multi(ty)                                                      \
  template <typename... Ts>                                                    \
  std::ostream &operator<<(std::ostream &s, const ty<Ts...> &t) {              \
    for (const auto &x : t)                                                    \
      s << x << " ";                                                           \
    return s;                                                                  \
  }
printer_multi(vector);
printer_multi(set);
printer_multi(unordered_set);
printer_multi(multiset);
printer_multi(unordered_multiset);
printer_multi(map);
printer_multi(unordered_map);
#undef printer_multi

#define bit(x, i) (x & (1 << i))
#define all(c) (c).begin(), (c).end()

template <typename T> //
using max_heap = priority_queue<T>;
template <typename T> //
using min_heap = priority_queue<T, vector<T>, greater<T>>;

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
template <typename T> using uset = unordered_set<T>;
template <typename T> using v = vector<T>;

class Solution {
public:
  int longestIncreasingPath(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vvi dp(n, vi(m, 0));

    const v<pii> dirs = {
      {  0,  1 },
      {  0, -1 },
      {  1, 0 },
      { -1, 0 },
    };

    auto check = [&](int i, int j) {
      return i >= 0 && i < n && j >= 0 && j < m;
    };

    auto dfs = [&](auto&& self, int i, int j) {
      if (dp[i][j])
        return dp[i][j];

      int x = matrix[i][j];
      int res = 1;
      for (auto& d: dirs) {
        int ni = i + d.first;
        int nj = j + d.second;

        if (!check(ni, nj))
          continue;

        if (matrix[ni][nj] > x)
          res = max(res, 1 + self(self, ni, nj));
      }

      return dp[i][j] = res;
    };

    int res = 1;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        res = max(res, dfs(dfs, i, j));
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  return 0;
}
