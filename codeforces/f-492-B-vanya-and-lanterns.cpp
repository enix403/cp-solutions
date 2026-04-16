#include <iostream>
#include <vector>
#include <algorithm>

#define ll unsigned long long int

using namespace std;

template<typename T>
inline T next()
{
    T x;
    cin >> x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto n = next<int>();
    auto l = next<ll>();

    vector<ll> laterns;
    laterns.reserve(n);

    for (int i = 0; i < n; ++i)
        laterns.push_back(next<ll>());

    std::sort(laterns.begin(), laterns.end());

    ll maxdiff = 0;
    for (int i = 0; i < n - 1; ++i)
        maxdiff = std::max(laterns[i + 1] - laterns[i], maxdiff);

    double res = std::max({
        (double)laterns[0],
        (double)(l - laterns[n - 1]),
        maxdiff / 2.0
    });

    cout << res << endl;
}
