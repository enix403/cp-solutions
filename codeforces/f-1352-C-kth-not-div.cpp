#include <iostream>

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

    int t;
    cin >> t;

    while (t--)
    {
        auto n = next<ll>();
        auto k = next<ll>();

        auto b = n - 1;
        auto i = k - 1;

        auto row = i / b;
        auto col = i % b;

        cout << (n * row + 1) + col << '\n';
    }
}
