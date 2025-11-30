#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> p(n), res(n);

    for (int i = 0, cur = 1; i < n; ++i) {
      p[i] = cur;
      cur *= nums[i];
    }

    for (int i = n - 1, cur = 1; i >= 0; --i) {
      res[i] = cur * p[i];
      cur *= nums[i];
    }
    return res;
  }
};
