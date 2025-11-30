#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  array<char, 26> id(const string &str) {
    array<char, 26> res{0};
    for (int i = 0; i < str.size(); ++i) {
      res[str[i] - 'a']++;
    }
    return res;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    map<array<char, 26>, vector<string>> res;
    for (const auto &s : strs) {
      res[id(s)].push_back(s);
    }
    vector<vector<string>> res2;
    for (auto &&[_, vs] : res)
      res2.push_back(std::move(vs));
    return res2;
  }
};
