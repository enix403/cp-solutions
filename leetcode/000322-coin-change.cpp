#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
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
class Solution {
public:
  map<pii, int> dp;
  int solve(vi& arr, int i, int t) {
    if (t < 0)
      return -1;

    if (t == 0)
      return 0;

    if (i == 0)
      return -1; // since t == 0 is already handled by above

    pii p = { i, t };

    if (dp.count(p))
      return dp[p];

    int a = solve(arr, i - 1, t);
    int b = solve(arr, i, t - arr[i - 1]);
    int res = a;

    if (b != -1) {
      int val = 1 + b;
      res = res == -1 ? val : min(res, val);
    }

    return dp[p] = res;
  }

  int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    return solve(coins, n, amount);

    // for (int i = 0; i <= n; ++i) {
    //   for (int t = 0; t <= amount; ++t) {
    //     int v = solve(coins, i, t);
    //     if (v == INT_MAX) v = -1;
    //     cout << setw(4) << std::right << v << ' ';
    //   }
    //   cout << endl;
    // }
  }
};

int main() {
  Solution s;
  // vi nums = {10,9,2,5,3,7,101,18};
  // vi nums = {0,1,0,3,2,3};
  vi nums = {1};
  cout << s.coinChange(nums, 0) << endl;
  // cout << boolalpha << s.canPartition(nums) << endl;
}
