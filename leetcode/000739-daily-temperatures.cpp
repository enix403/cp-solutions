#include <cstdint>
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
  vector<int> dailyTemperatures(vector<int> &arr) {
    stack<pii> s;
    vector<int> res(arr.size(), 0);
    for (int i = 0; i < arr.size(); ++i) {
      int x = arr[i];
      while (s.size() && x > s.top().first) {
        int j = s.top().second;
        s.pop();
        int diff = i - j;
        res[j] = diff;
      }
      s.push({x, i});
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {73, 74, 75, 71, 69, 72, 76, 73};
  s.dailyTemperatures(arr);
}
