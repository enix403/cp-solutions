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

struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right)
  {}
};

TreeNode* buildTree(const std::vector<std::optional<int>>& arr)
{
  if (arr.empty() || !arr[0].has_value()) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(arr[0].value());
  std::queue<TreeNode*> q;
  q.push(root);

  int i = 1;
  while (!q.empty() && i < arr.size()) {
    TreeNode* cur = q.front();
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

#define printer_t(ty, expr)                                     \
  template <typename... Ts>                                     \
  std::ostream& operator<<(std::ostream& s, const ty<Ts...>& t) \
  {                                                             \
    return s << expr;                                           \
  }

printer_t(pair, "(" << t.first << "," << t.second << ")");
#undef printer_t

#define printer_multi(ty)                                       \
  template <typename... Ts>                                     \
  std::ostream& operator<<(std::ostream& s, const ty<Ts...>& t) \
  {                                                             \
    for (const auto& x : t)                                     \
      s << x << " ";                                            \
    return s;                                                   \
  }
printer_multi(vector);
printer_multi(set);
printer_multi(unordered_set);
printer_multi(multiset);
printer_multi(unordered_multiset);
printer_multi(map);
printer_multi(unordered_map);
#undef printer_multi

// -------------

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
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef vector<pii> vii;
template <typename K, typename V>
using umap = unordered_map<K, V>;
template <typename T>
using uset = unordered_set<T>;
template <typename T>
using v = vector<T>;

class Solution
{
public:
  int maximumDetonation(vector<vector<int>>& bombs) {
    int n = bombs.size();

    v<v<int>> g(n);

    for (int i = 0; i < n; ++i) {
      ll xi = bombs[i][0];
      ll yi = bombs[i][1];
      ll ri = bombs[i][2];
      ri*=ri;
      for (int j = i + 1; j < n; ++j) {
        ll xj = bombs[j][0];
        ll yj = bombs[j][1];
        ll rj = bombs[j][2];
        rj *= rj;

        ll dx = xi - xj;
        ll dy = yi - yj;
        ll dst = dx*dx + dy*dy;

        if (dst <= ri) {
          // edge from i -> j
          g[i].push_back(j);
        }

        if (dst <= rj) {
          // edge from j -> i
          g[j].push_back(i);
        }
      }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      stack<int> s;
      v<bool> vis(n, false);
      s.push(i);

      int len = 0;
      while (s.size()) {
        int j = s.top();
        s.pop();
        if (vis[j])
          continue;

        vis[j] = true;
        len ++;

        for (auto x: g[j]) {
          if (vis[x])
            continue;

          s.push(x);
        }
      }

      res = max(res, len);
    }

    return res;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  v<v<int>> bombs = {{1,2,3},{2,3,1},{3,4,2},{4,5,3},{5,6,4}};

  cout << Solution().maximumDetonation(bombs) << endl;

  return 0;
}
