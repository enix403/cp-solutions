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
  int characterReplacement(string s, int k) {
    int n = s.length();
    unordered_map<char, int> f;

    auto is_valid = [&](int l, int r) -> bool {
      int F = 0;
      for (auto [k, v] : f) {
        F = max(F, v);
      }
      int len = r - l + 1;
      return F >= len - k;
    };

    int res = 0;

    for (int l = 0, r = 0; r < n; ++r) {
      f[s[r]]++;

      while (!is_valid(l, r)) {
        f[s[l]]--;
        l++;
      }

      res = max(res, r - l + 1);
    }

    return res;
  }
};

int main() {
  Solution s;
  auto res = s.characterReplacement("AABABBA", 1);
  cout << res << endl;
}
