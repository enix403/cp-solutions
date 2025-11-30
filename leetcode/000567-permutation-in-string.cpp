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
  bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();

    if (n1 > n2)
      return false;

    unordered_map<char, int> h1, h2;
    for (char c : s1)
      ++h1[c];

    auto check = [&]() -> bool {
      for (int i = 0; i < 26; ++i)
        if (h1['a' + i] != h2['a' + i])
          return false;
      return true;
    };

    for (int i = 0; i < n2; ++i) {
      char c = s2[i];
      h2[c]++;

      if (i >= n1)
        h2[s2[i - n1]]--;

      if (i >= n1 - 1 && check())
        return true;
    }

    return false;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
  // s.maxSlidingWindow(arr, 3);
  // cout << res << endl;
  return 0;
}
