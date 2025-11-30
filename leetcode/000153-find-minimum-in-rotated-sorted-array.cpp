#include <cinttypes>
#include <cstdint>
#include <iostream>
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
  int findMin(vector<int> &nums) {
    int n = nums.size();
    int l = 0;
    int r = n - 1;

    while (l <= r) {
      int m = (l + r) / 2;
      if (nums[r] > nums[m]) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return nums[r];
  }
};

int main() {
  vector<int> arr = {3, 1, 2};
  Solution s;
  cout << s.findMin(arr) << endl;
  return 0;
}
