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
  int dfs(Node root) {
    if (!root)
      return 0;

    int l = dfs(root->left);
    int r = dfs(root->right);

    res = max(res, 1 + r + l);

    return 1 + max(l, r);
  }
  int diameterOfBinaryTree(TreeNode *root) {
    res = 0;
    dfs(root);
    return res - 1;
  }
};
