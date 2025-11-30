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

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      int a = nums[l];
      int p = nums[m];
      int b = nums[r];

      if (target == p)
        return m;

      if (a <= p) {
        if (a <= target && target < p) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else {
        if (p < target && target <= b) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    return -1;
  }
};
