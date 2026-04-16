#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

#define CDIV(x, y) (((x) % (y)) ? (x) / (y) + 1 : (x) / (y))

void solve(int a, int b, int c, string mv)
{
    int n = mv.length();

    int ra = 0;
    int rb = 0;
    int rc = 0;

    for (char c : mv)
    {
        if (c == 'S')
            ra++;
        else if (c == 'R')
            rb++;
        else if (c == 'P')
            rc++;
    }


    int wins = min(a, ra) + min(b, rb) + min(c, rc);

    if (wins >= CDIV(n, 2))
    {
        cout << "YES\n";
        for (int i = 0; i < n; ++i)
        {
            char ch = mv[i];
            if (ch == 'S')
            {
                if (a)
                {
                    a--;
                    mv[i] = 'R';
                }
                else
                {
                    mv[i] = '-';
                }
            }
            else if (ch == 'R')
            {
                if (b)
                {
                    b--;
                    mv[i] = 'P';
                }
                else
                {
                    mv[i] = '-';
                }
            }
            else if (ch == 'P')
            {
                if (c)
                {
                    c--;
                    mv[i] = 'S';
                }
                else
                {
                    mv[i] = '-';
                }
            }
        }


        for (int i = 0; i < n; ++i)
        {
            if (mv[i] != '-')
                continue;

            if (a)
            {
                a--;
                mv[i] = 'R';
            }
            else if (b)
            {
                b--;
                mv[i] = 'P';
            }
            else if (c)
            {
                c--;
                mv[i] = 'S';
            }
        }

        cout << mv << '\n';
    }
    else
    {
        cout << "NO\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        string mv;
        cin >> mv;
        solve(a, b, c, mv);
    }
}