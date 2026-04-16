#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;

/*
0 = up
1 = down

01
*/

#define ll long long

void solve(int n, const vector<int>& v)
{
    if (v[0] == 1)
    {
        // n + 1 -> 1 -> 2 -> ...
        cout << n + 1;
        for (int i = 1; i <= n; ++i)
        {
            cout << ' ' << i;
        }
        cout << '\n';
        return;
    }

    if (v[n - 1] == 0)
    {
        // 1 -> 2 -> ... -> n + 1
        for (int i = 1; i <= n; ++i)
        {
            cout << i << ' ';
        }
        cout << n + 1;
        cout << '\n';
        return;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (v[i] == 0 && v[i + 1] == 1)
        {
            for (int j = 0; j <= i; ++j)
            {
                cout << j + 1 << ' ';
            }

            cout << n + 1;

            for (int j = i + 1; j < n; ++j)
            {
                cout << ' ' << j + 1;
            }

            cout << '\n';
            return;
        }
    }

    // not possible
    cout << "-1\n";
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }

        solve(n, v);
    }
}