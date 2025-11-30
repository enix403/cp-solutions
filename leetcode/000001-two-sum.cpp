#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int t) {
    unordered_map<int, int> idx;
    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      if (idx.count(t - x))
        return {idx[t - x], i};
      idx[x] = i;
    }
    return {};
  }
};
