#include <iostream>
#include <utility>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, j;

    for (int r = 0; r < 5; ++r)
    {
        for (int c = 0; c < 5; ++c)
        {
            int v;
            cin >> v;
            if (v == 1)
            {
                i = r;
                j = c;
            }
        }
    }

    cout << abs(i - 2) + abs(j - 2) << '\n';
}
