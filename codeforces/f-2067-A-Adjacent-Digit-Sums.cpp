#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool is_ten(int x)
{
    switch (x)
    {
        case 1:
        case 10:
        case 100:
        case 1000: return true;
    }
    return false;
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
        int x, y;
        cin >> x >> y;

        bool ok = false;

        if (y > x)
        {
            if (y - x == 1)
                ok = true;
        }
        else if ((x - y - 8) % 9 == 0)
        {
            ok = true;
        }

        if (ok)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}
