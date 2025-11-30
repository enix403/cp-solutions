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
  int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size();

    // dp[i] == (len of LIS ending at i, count of such IS's)
    vii dp(n);
    int maxlen = 0;
    int res;

    for (int i = 0; i < n; ++i) {
      int prev_max_len = 0;
      int prev_count = 1;
      for (int j = 0; j < i; ++j) {
        if (nums[j] < nums[i]) {
          if (prev_max_len == dp[j].first) {
            prev_count += dp[j].second;
          }
          else if (dp[j].first > prev_max_len) {
            prev_max_len = dp[j].first;
            prev_count = dp[j].second;
          }
        }
      }
      int len = prev_max_len + 1;
      dp[i] = {len, prev_count};

      if (len == maxlen) {
        res += prev_count;
      }
      else if (len > maxlen) {
        maxlen = len;
        res = prev_count;
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;
  // vi arr = {1,3,5,4,7};
  vi arr = {2,2,2,2,2};
  auto res = s.findNumberOfLIS(arr);
  // cout << res << endl;

  return 0;
}

