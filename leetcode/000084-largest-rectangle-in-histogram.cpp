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
  int largestRectangleArea(vector<int> &arr) {
    int n = arr.size();
    vector<int> res(n, -1);

    stack<int> st;
    for (int i = 0; i < n; ++i) {
      int x = arr[i];
      while (st.size() && x < arr[st.top()]) {
        int k = st.top();
        st.pop();
        res[k] = i - k;
      }
      st.push(i);
    }
    while (st.size()) {
      int k = st.top();
      st.pop();
      res[k] = n - k;
    }

    for (auto x : res)
      cout << x << ",";
    cout << endl;

    for (int i = n - 1; i >= 0; --i) {
      int x = arr[i];
      while (st.size() && x < arr[st.top()]) {
        int k = st.top();
        st.pop();
        res[k] += k - i;
      }
      st.push(i);
    }
    while (st.size()) {
      int k = st.top();
      st.pop();
      res[k] += k + 1;
    }

    for (auto x : res)
      cout << x << ",";
    cout << endl;

    int maxArea = -1;
    for (int i = 0; i < n; ++i) {
      int area = (res[i] - 1) * arr[i];
      maxArea = max(maxArea, area);
    }
    cout << maxArea << endl;
    return maxArea;
  }
};

int main() {
  // vector<int> arr = {2, 1, 5, 6, 2, 3};
  vector<int> arr = {1, 1};
  Solution s;
  s.largestRectangleArea(arr);
  return 0;
}
