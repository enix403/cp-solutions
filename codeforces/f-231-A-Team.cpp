#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int res = 0;

    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b + c > 1)
            res++;
    }

    cout << res << '\n';
}
