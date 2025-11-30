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
  int maxProfit(vector<int> &prices) {
    int res = 0;
    int minp = INT_MAX;
    for (int x : prices) {
      minp = min(minp, x);
      res = max(res, x - minp);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
  // s.maxSlidingWindow(arr, 3);
  // cout << res << endl;
  return 0;
}
