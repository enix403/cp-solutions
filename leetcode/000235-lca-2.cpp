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

using Node = TreeNode *;

class BoolPair {
  // bit 0 = first elem
  // bit 1 = second elem
  short val;

public:
  BoolPair(bool a, bool b) { val = (short)(a) | ((short)(b) << 1); }

  bool first() const { return val & 1; }

  bool second() const { return val & 0b10; }
};

class Solution {
public:
  int a, b;
  bool found;
  Node res;

  BoolPair dfs(Node node) {
    if (!node || found)
      return {false, false};

    BoolPair l = dfs(node->left);
    BoolPair r = dfs(node->right);

    int val = node->val;

    bool fa = val == a || l.first() || r.first();
    bool fb = val == b || l.second() || r.second();

    if (!found && fa && fb) {
      res = node;
      found = true;
    }

    return BoolPair(fa, fb);
  }

  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    a = p->val;
    b = q->val;
    found = false;
    dfs(root);
    return res;
  }
};

// SINCE THE INPUT TREE IS A BST, THE FOLLOWING IS ENOUGH FOR THIS PROBLEM.
/*
class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

    // If both a and b are strictly less then current node, the LCA is
    // in the left subtree.
    // If both a and b are strictly greater then current node, the LCA is
    // in the right subtree.
    // Otherwise if node value is in between a and b, then this node IS the LCA

    int a = p->val;
    int b = q->val;

    while (1) {
      int val = root->val;
      if (a < val && b < val) {
        root = root->left;
      } else if (a > val && b > val) {
        root = root->right;
      } else {
        return root;
      }
    }
  }
};
*/

int main() {
  Solution s;
  Node root = buildTree({6, 2, 8, 0, 4, 7, 9, nullopt, nullopt, 3, 5});
  Node res = s.lowestCommonAncestor(root, new TreeNode(2), new TreeNode(8));
  cout << res->val << endl;
  return 0;
}