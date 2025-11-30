#include <cinttypes>
#include <cstdint>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define pii pair<int, int>

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      while (q.size() && x >= nums[q.back()]) {
        q.pop_back();
      }

      q.push_back(i);

      while (q.size() && i - q.front() >= k) {
        q.pop_front();
      }

      if (i >= k - 1) {
        res.push_back(q.front());
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
  s.maxSlidingWindow(arr, 3);
  // cout << res << endl;
  return 0;
}
