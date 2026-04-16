#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    string s;

    while (t--)
    {
        int n;
        cin >> n;
        cin >> s;

        int res = 0;

        for (int i = 0; i < n - 1; i++)
        {
            while (s[i] == s[i + 2])
                i++;

            res++;
        }

        cout << res << '\n';
    }

    return 0;
}