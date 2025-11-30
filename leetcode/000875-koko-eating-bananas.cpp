class Solution {
public:
  int minEatingSpeed(vector<int> &piles, int h) {
    auto check = [&](int k) -> bool {
      long long s = 0;
      for (int x : piles)
        s += (x / k) + (x % k != 0);
      return s <= h;
    };

    int l = 1;
    int r = 0;
    for (int x : piles)
      r = max(r, x);

    int k = r + 1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (check(m)) {
        k = min(k, m);
        r = m - 1;
      } else {
        l = m + 1;
      }
    }

    // cout << k << endl;
    return k;
  }
};
