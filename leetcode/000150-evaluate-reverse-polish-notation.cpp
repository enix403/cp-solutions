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

struct Token
{
  union {
    char c;
    int32_t i;
  } payload;
  bool isOperator;

  Token(const string& s)
  {
    static constexpr char OPS[] = "+-*/";
    for (const char op : OPS) {
      if (s.length() == 1 && s[0] == op) {
        payload.c = op;
        isOperator = true;
        return;
      }
    }
    isOperator = false;
    payload.i = stoi(s);
  }

  inline const int value() const { return payload.i; }

  inline const char oper() const { return payload.c; }

  int eval(int a, int b)
  {
    switch (oper()) {
      case '+':
        return a + b;
      case '-':
        return a - b;
      case '*':
        return a * b;
      case '/':
        return a / b;
    }
    return 0;
  }
};

class Solution
{
public:
  int evalRPN(vector<string>& tokens)
  {
    queue<Token> q;
    for (const string& ts : tokens) {
      q.push(ts);
    }

    if (q.size() == 1) {
      return q.front().value();
    }

    stack<int> s;
    s.push(q.front().value());
    q.pop();
    s.push(q.front().value());
    q.pop();

    while (q.size()) {
      auto x = q.front();
      q.pop();

      if (x.isOperator) {
        int b = s.top();
        s.pop();
        int a = s.top();
        s.pop();

        s.push(x.eval(a, b));
      } else {
        s.push(x.value());
      }
    }

    return s.top();
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  Solution s;

  v<string> toks = {"2","1","+","3","*"};
  // v<string> toks = {"4","13","5","/","+"};
  // v<string> toks = {"10", "6", "9",  "3", "+", "-11", "*",
                    // "/",  "*", "17", "+", "5", "+"};
  cout << s.evalRPN(toks) << endl;

  return 0;
}
