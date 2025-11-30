#include <queue>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> count;
    for (int x : nums)
      count[x]++;
    min_heap<pair<int, int>> q; // min heap

    for (int x : nums) {
      int c = count[x];
      if (!c)
        continue;
      if (q.size() < k) {
        q.push({c, x});
      } else {
        if (q.top().first < c) {
          q.pop();
          q.push({c, x});
        }
      }
      count[x] = 0;
    }

    vector<int> res;
    while (q.size()) {
      res.push_back(q.top().second);
      q.pop();
    }

    return res;
  }
};
