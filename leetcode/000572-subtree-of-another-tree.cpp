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
class Solution {
public:
  bool isSame(TreeNode *a, TreeNode *b) {
    if (bool(a) != bool(b))
      return false;

    if (!a)
      return true;

    if (a->val != b->val)
      return false;

    return isSame(a->left, b->left) && isSame(a->right, b->right);
  }

  bool isSubtree(TreeNode *root, TreeNode *sub) {
    if (!root && !sub)
      return true;

    if (!root || !sub)
      return false;

    if (root->val == sub->val) {
      if (isSame(root->left, sub->left) && isSame(root->right, sub->right))
        return true;
    }

    return isSubtree(root->left, sub) || isSubtree(root->right, sub);
  }
};
