#include <iostream>
#include <vector>
// #include <limits>

#define ll long long int

using namespace std;

// template<typename T>
// void print_vec(const vector<T>& vec)
// {
//     for (const auto& v : vec)
//     {
//         cout << v << " ";
//     }
//     cout << endl;
// }


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

    vector<ll> maxs;
    vector<ll> sums;

    while (t--)
    {
        long n = next<int>();
        long Q = next<int>();

        maxs.clear();
        maxs.reserve(n);

        sums.clear();
        sums.reserve(n);

        ll max = 0;
        ll sum = 0;

        for (int i = 0; i < n; ++i)
        {
            auto x = next<ll>();

            max = std::max(max, x);
            sum += x;

            maxs.push_back(max);
            sums.push_back(sum);
        }

        while (Q--)
        {
            auto q = next<int>();

            ll left = 0;
            ll right = n - 1;

            ll count = 0;

            while (left <= right)
            {
                ll mid = (right + left) / 2;

                // Check if middle element is
                // less than or equal to key
                if (maxs[mid] <= q)
                {

                    // At least (mid + 1) elements are there
                    // whose values are less than
                    // or equal to key
                    count = mid + 1;
                    left = mid + 1;
                }

                // If key is smaller, ignore right half
                else
                    right = mid - 1;
            }

            cout << (count ? sums[count - 1] : 0) << ' ';
        }

        cout << '\n';
    }
}

/*
1
4 1
1 2 1 5
8
*/