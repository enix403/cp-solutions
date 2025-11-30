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
  void dfs(Node node, int maxval) {
    if (!node)
      return;

    if (node->val >= maxval)
      res++;

    maxval = max(maxval, node->val);
    dfs(node->left, maxval);
    dfs(node->right, maxval);
  }

  int goodNodes(TreeNode *root) {
    res = 0;
    dfs(root, root->val);
    return res;
  }
};
