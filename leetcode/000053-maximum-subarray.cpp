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
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define pii pair<int, int>

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int prev = 0;
    int res = INT_MIN;

    for (int x : nums) {
      prev = max(x, prev + x);
      res = max(res, prev);
    }

    return res;
  }
};
