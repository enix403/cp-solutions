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
  int longestConsecutive(vector<int> &nums) {
    // return q;
    unordered_set<int> p;
    for (int x : nums)
      p.insert(x);

    int res = 0;
    for (int x : p) {
      if (p.count(x - 1))
        continue;

      int i = 1;
      while (p.count(x + 1)) {
        i++;
        x++;
      }

      res = max(res, i);
    }

    return res;
  }
};
