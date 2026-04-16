#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int x = 0;

    char op[4];
    while (n--)
    {
        cin >> op;
        if (op[1] == '+')
            x++;
        else
            x--;
    }

    cout << x << '\n';
}
