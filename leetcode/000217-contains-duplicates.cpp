#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> found;
    for (auto x : nums) {
      if (found[x])
        return true;
      found[x] = true;
    }
    return false;
  }
};
