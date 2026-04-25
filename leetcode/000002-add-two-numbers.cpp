// clang++ -std=c++17 -DCUSTOM_DEBUG main.cpp && ./a.out

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
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

using namespace std;

#ifdef CUSTOM_DEBUG
#include "parts/leetcode-tree.h"
#include "parts/printer.h"
#endif

// ----------------
// start copy from here

template <typename Container, typename Func>
auto map(const Container& c, Func f)
{
  std::vector<decltype(f(*c.begin()))> result;
  result.reserve(c.size());
  for (const auto& x : c)
    result.push_back(f(x));
  return result;
}

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

const v<pii> DIRS = {
    { 0,  1},
    { 0, -1},
    { 1,  0},
    {-1,  0}
};

// ----------------

class Solution
{
public:
  using Node = ListNode*;

  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    int c = 0;
    Node a = l1;
    Node b = l2;

    Node head = new ListNode();
    Node store = head;

    while (a || b || c) {
      int v = 0, w = 0;
      if (a) {
        v = a->val;
        a = a->next;
      }

      if (b) {
        w = b->val;
        b = b->next;
      }

      int res = v + w + c;
      c = res / 10;
      res = res % 10;

      store->next = new ListNode(res);
      store = store->next;
    }

    return head->next;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  // vi arr = {1,3,4,2,2};
  // vi arr = {3,1,3,4,2};
  // vi arr = {3,3,3,3,3};
  // cout << s.findDuplicate(arr) << endl;

  return 0;
}
