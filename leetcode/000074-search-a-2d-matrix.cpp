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
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    auto get = [&](int i) -> int {
      int r = i / m;
      int c = i % m;
      return matrix[r][c];
    };
    
    int l = 0;
    int r = n * m - 1;
    
    while (l <= r) {
      int h = (l + r) / 2;
      int val = get(h);
      if (val == target)
        return true;
      else if (target < val)
        r = h - 1;
      else
        l = h + 1;
    }
    return false;
  }
};

// int main() {
//   // vector<int> arr = {2, 1, 5, 6, 2, 3};
//   vector<int> arr = {1, 1};
//   Solution s;
//   s.largestRectangleArea(arr);
//   return 0;
// }
