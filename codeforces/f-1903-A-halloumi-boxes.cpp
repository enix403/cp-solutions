#include <iostream>
#include <limits>

using namespace std;

inline int next()
{
    int x;
    cin >> x;
    return x;
}

int main()
{
    int t = next();

    while (t--) {
        int n = next();
        int k = next();

        int a = 0;

        bool sorted = true;

        for (int i = 0; i < n; ++i) {
            int b = next();

            if (b < a) {
                sorted = false;
                cin.ignore(numeric_limits<int>::max(), '\n');
                break;
            }

            a = b;
        }

        bool sortable = sorted || k > 1;

        cout << (sortable ? "YES" : "NO") << '\n';
    }

    return 0;
}