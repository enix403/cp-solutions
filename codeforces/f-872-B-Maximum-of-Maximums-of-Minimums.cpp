#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

#define all(v)       (v).begin(), (v).end()
#define rall(v)      (v).rbegin(), (v).rend()
#define allop(op, v) op(all(v))

#define ll   long long
#define ull  unsigned long long
#define pi   pair<int, int>
#define pll  pair<ll, ll>
#define umap unordered_map
#define uset unordered_set
#define vi   vector<int>
#define vll  vector<ll>
#define vvi  vector<vector<int>>
#define vvll vector<vector<ll>>

template<typename T>
using vv = vector<vector<T>>;

template<typename T>
using max_heap = priority_queue<T>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

/* --------------------- */

int main()
{
    FAST_IO;

    int n, k;
    cin >> n >> k;

    ll arr_min = numeric_limits<ll>::max();
    ll arr_max = numeric_limits<ll>::min();
    ll end_max = numeric_limits<ll>::min();

    for (int i = 0; i < n; ++i)
    {
        ll x;
        cin >> x;

        if (i == 0 || i == n - 1)
            end_max = max(end_max, x);

        arr_min = min(arr_min, x);
        arr_max = max(arr_max, x);
    }

    if (k == 1)
        cout << arr_min;
    else if (k == 2)
        cout << end_max;
    else
        cout << arr_max;

    cout << '\n';
}
