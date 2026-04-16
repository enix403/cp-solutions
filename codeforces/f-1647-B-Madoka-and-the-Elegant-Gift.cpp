#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <ios>
#include <iostream>
#include <vector>

using namespace std;


#define ll long long

void solve(int n, int m, const vector<vector<int>>& g)
{
    // n = g.size();
    // m = g[0].size();

    for (int r = 0; r < n - 1; ++r)
    {
        for (int c = 0; c < m - 1; ++c)
        {
            // find a 2x2 region that has exactly a single 0, which means
            // that there is an intersection of nice rectangles
            int sum = (g[r][c] + g[r + 1][c] + g[r][c + 1] + g[r + 1][c + 1]);

            if (sum == 3)
            {
                // intersection found
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    /*solve(0, 0,
          {
            { 1, 0, 0 },
            { 0, 1, 1 },
            { 0, 1, 1 },
    });*/

    // return 0;

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;

        std::vector<std::vector<int>> grid(n, std::vector<int>(m));
        for (int r = 0; r < n; ++r)
        {
            string l;
            cin >> l;
            for (int c = 0; c < m; ++c)
            {
                grid[r][c] = (int) (l[c] - '0');
            }
        }

        solve(n, m, grid);
    }
}