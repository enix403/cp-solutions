#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        // getline(cin, s);
        cin >> s;
        int n = s.length();
        if (n > 10)
            cout << s[0] << n - 2 << s[n - 1] << '\n';
        else
            cout << s << '\n';
    }
}