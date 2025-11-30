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
  bool search(vector<int> &nums, int target) {
    int n = nums.size();

    // find the rotation point k
    int k = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1]) {
        k = i;
        break;
      }
    }

    // do a regular binary search, offseting each index by +k

    int l = 0;
    int r = n - 1;

    while (l <= r) {
      int m = l + (r - l) / 2;
      int p = (m + k) % n;

      if (target == nums[p])
        return true;

      if (target < nums[p])
        r = m - 1;
      else
        l = m + 1;
    }

    return false;
  }
};
