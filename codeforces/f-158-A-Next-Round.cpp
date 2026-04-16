#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    k--;

    vector<int> scores(n, 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> scores[i];
    }

    int res = 0;
    for (auto v : scores)
    {
        if (v >= scores[k] && v > 0)
            res++;
    }

    cout << res << '\n';
}
