#include <ios>
#include <iostream>

using namespace std;

inline int next()
{
    int x;
    cin >> x;
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);

    int t = next();

    while (t--)
    {
        int n = next();
        int x = next();

        int prev = 0;
        int res = 0;

        for (int i = 0; i < n; ++i)
        {
            int p = next();
            res = max(res, p - prev);
            prev = p;
        }

        int last_d = x - prev;
        res = max(res, last_d * 2);

        cout << res << '\n';
    }
}
