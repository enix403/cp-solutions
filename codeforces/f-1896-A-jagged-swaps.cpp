#include <ios>
#include <iostream>

using namespace std;

template<typename T = int>
inline T next()
{
    T x;
    cin >> x;
    return x;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    int t = next();

    while (t--)
    {
        int n = next();
        bool sorted = true;

        int first = next();
        int prev = first;

        for (int i = 1; i < n; ++i)
        {
            int x = next();

            if (x < prev)
            {
                sorted = false;
            }

            prev = x;
        }

        bool sortable = sorted || (first == 1);

        cout << (sortable ? "YES" : "NO") << '\n';
    }

    return 0;
}