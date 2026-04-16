#include <ios>
#include <iostream>
#include <random>

using namespace std;

inline int next()
{
    int x;
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
        int chunk = 0;
        int max_chunk = 0;
        int empty = 0;

        for (int i = 0; i < n; ++i)
        {
            char c;
            cin >> c;

            if (c == '#')
            {
                max_chunk = max(max_chunk, chunk);
                chunk = 0;
            }
            else
            {
                empty++;
                chunk++;
            }
        }

        max_chunk = max(max_chunk, chunk);

        int res = max_chunk >= 3 ? 2 : empty;
        
        cout << res << '\n';
    }
}
