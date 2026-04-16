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
    string s;
    while (t--)
    {
        cin >> s;
        int res = 0;
        for (int i = 0; i < s.length(); ++i)
            if (s[i] == '1')
                res++;

        cout << res << '\n';
    }
}
