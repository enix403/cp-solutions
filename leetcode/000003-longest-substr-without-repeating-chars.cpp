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
  int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if (n <= 1)
      return n;
    int l = 0;
    int r = 0;

    unordered_map<char, int> c;

    auto is_valid = [&]() -> bool {
      for (auto [_, count] : c) {
        if (count > 1)
          return false;
      }
      return true;
    };

    int maxlen = 1;
    // int maxi = 0;

    c[s[l]] = 1;
    while (l <= r && r < n - 1) {
      r++;
      c[s[r]]++;

      while (!is_valid()) {
        c[s[l]]--;
        l++;
      }
      int len = r - l + 1;
      if (len >= maxlen) {
        maxlen = len;
        // maxi = l;
      }
    }

    return maxlen;
  }
};

int main() {
  Solution s;
  int res = s.lengthOfLongestSubstring("pwwkew");
  cout << res << endl;
  return 0;
}
