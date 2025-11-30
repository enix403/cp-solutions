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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using Node = TreeNode *;

class Solver {
public:
  vector<int> &preorder;
  vector<int> &inorder;

  Solver(vector<int> &preorder, vector<int> &inorder)
      : preorder(preorder), inorder(inorder) {}

  Node solve(int pa, // preorder start inclusive
             int pb, // preorder end exclusive
             int ia, // inorder start inclusive
             int ib  // inorder start exclusive
  ) {
    int n = pb - pa;

    if (n == 0)
      return nullptr;

    int root = preorder[pa];
    int k; // relative to ia
    for (int i = 0; i < n; ++i) {
      if (inorder[ia + i] == root) {
        k = i;
        break;
      }
    }

    int nl = k;          // number of left nodes
    int nr = n - nl - 1; // number of right nodes

    Node node = new TreeNode();
    node->val = root;

    node->left = solve(pa + 1, pa + 1 + nl, ia, ia + nl);
    node->right = solve(pb - nr, pb, ib - nr, ib);

    return node;
  }
};

class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return Solver(preorder, inorder).solve(0, n, 0, n);
  }
};