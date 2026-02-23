#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef CUSTOM_DEBUG
#include "parts/leetcode-tree.h"
#include "parts/printer.h"
#endif

// ----------------

#define all(c) (c).begin(), (c).end()
#define range2d(r, c, R, C) ((r) >= 0 && (r) < (R) && (c) >= 0 && (c) < (C))

template <typename T>  //
using max_heap = priority_queue<T>;
template <typename T>  //
using min_heap = priority_queue<T, vector<T>, greater<T>>;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned short us;

//
typedef vector<int> vi;
typedef vector<vi> vvi;
//
typedef vector<ll> vl;
typedef vector<vl> vvl;
//
typedef vector<bool> vb;
typedef vector<vb> vvb;
//
typedef pair<int, int> pii;
typedef vector<pii> vii;
//
typedef pair<ll, ll> pll;
// clang-format off
template <typename T> using v = vector<T>;
template <typename T> using vv = vector<vector<T>>;
template <typename K, typename V> using umap = unordered_map<K, V>;
template <typename T> using uset = unordered_set<T>;
// clang-format on

// todo generator
const v<pii> DIRS = {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

// ----------------

const int INF = INT_MAX;

class Solution
{
public:
  int L;
  vvi adj;
  vi d;

  void dijsktra(int s)
  {
    int n = adj.size();
    d.assign(n, INF);

    d[s] = 0;

    min_heap<pii> q;
    q.push({0, s});

    while (q.size()) {
      auto [dv, v] = q.top();
      q.pop();

      if (dv != d[v])
        continue;

      for (auto k : adj[v]) {
        int updated = d[v] + 1;
        if (updated < d[k]) {
          d[k] = updated;
          q.push({d[k], k});
        }
      }
    }
  }

  bool is_adj(const string& a, const string& b)
  {
    int diff = 0;
    for (int i = 0; i < L; ++i) {
      if (a[i] != b[i])
        diff++;
    }
    return diff == 1;
  }

  void build_graph(const vector<string>& words)
  {
    int n = words.size();
    adj.assign(n, {});
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (is_adj(words[i], words[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }
  }

  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    L = beginWord.length();

    int beginIndex = -1;
    int endIndex = -1;

    for (int i = 0; i < wordList.size(); ++i) {
      const auto& w = wordList[i];
      if (w == beginWord) {
        beginIndex = i;
      } else if (w == endWord) {
        endIndex = i;
      }
    }

    if (endIndex == -1)
      return 0;

    if (beginIndex == -1) {
      beginIndex = wordList.size();
      wordList.push_back(beginWord);
    }

    build_graph(wordList);
    dijsktra(beginIndex);

    int val = d[endIndex];
    return val == INF ? 0 : val + 1;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string beginWord = "hit";
  string endWord = "cog";
  v<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

  // string beginWord = "hit";
  // string endWord = "cog";
  // v<string> wordList = {"hot", "dot", "dog", "lot", "log"};

  Solution s;

  int res = s.ladderLength(beginWord, endWord, wordList);

  cout << res << endl;

  return 0;
}
