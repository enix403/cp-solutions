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
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[m] == target)
        return m;

      if (target < nums[m])
        r = m - 1;
      else
        l = m + 1;
    }

    return -1;
  }
};
