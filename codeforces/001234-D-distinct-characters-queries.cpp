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
#include <bitset>

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

// https://codeforces.com/problemset/problem/1234/D

ui mask(char c) {
  return 1u << (c - 'a');
}

v<ui> tree;
int n;

void build_tree(const string& s) {
  n = 1;
  while (n < s.size()) {
    n *= 2;
  }
  tree.assign(2 * n, 0);
  for (int i = 0; i < s.size(); ++i) {
    tree[n + i] = mask(s[i]);
  }

  for (int i = n - 1; i > 0; --i) {
    tree[i] = tree[2 * i] | tree[2 * i + 1];
  }
}

void update(int i, char c) {
  i += n;
  tree[i] = mask(c);
  while (i > 1) {
    i /= 2;
    tree[i] = tree[2 * i] | tree[2 * i + 1];
  }
}

ui query(int l, int r) {
  l += n;
  r += n;

  ui ans = 0;
  while (l <= r) {
    if (l % 2 == 1)
      ans |= tree[l++];

    if (r % 2 == 0)
      ans |= tree[r--];

    l /= 2;
    r /= 2;
  }
  // return bitset<32>(ans).count();
  return __builtin_popcount(ans);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int q;
  cin >> q;

  build_tree(s);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      // update
      int i;
      char c;
      cin >> i >> c;
      update(--i, c);
    }
    else {
      // query
      int l, r;
      cin >> l >> r;
      int res = query(--l, --r);
      cout << res << '\n';
    }
  }

  return 0;
}

/*

abacaba
5
2 1 4
1 4 b
1 5 b
2 4 6
2 1 7


*/
