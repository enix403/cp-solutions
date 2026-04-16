#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;

    if (m < n)
        swap(m, n);

    // now m >= n

    int res;
    if (m % 2 == 0)
    {
        res = n * m / 2;
    }
    else
    {
        res = n * (m - 1) / 2 + n / 2;
    }

    cout << res << '\n';
}
