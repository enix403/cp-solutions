#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <map>
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

// #define pb push_back
// #define fi first
// #define se second

template <typename T> //
using max_heap = priority_queue<T>;
template <typename T> //
using min_heap = priority_queue<T, vector<T>, greater<T>>;

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

class Solution {
public:
  int climbStairs(int n) {
    int a = 1;
    int b = 1;

    for (int i = 0; i < n - 1; ++i) {
      int t = a;
      a = a + b;
      b = t;
    }

    return a;
  }
};