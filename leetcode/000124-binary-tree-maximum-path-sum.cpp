#include <cinttypes>
#include <climits>
#include <cstdint>
#include <deque>
#include <iostream>
#include <memory>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define pii pair<int, int>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
using Node = TreeNode *;
class Solution {
public:
  int res;
  int dfs(Node node) {
    if (!node)
      return 0;

    int l = dfs(node->left);
    int r = dfs(node->right);

    res = max({res, node->val + max(l, 0) + max(r, 0)});

    return node->val + max({0, l, r});
  }

  int maxPathSum(TreeNode *root) {
    res = INT_MIN;
    dfs(root);
    return res;
  }
};
