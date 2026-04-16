#include <ios>
#include <iostream>
#include <cstdint>

using namespace std;

typedef uint64_t W;

template <typename T = int>
inline T next()
{
    T x;
    cin >> x;
    return x;
}


inline W xor_power(W n, W p)
{
    if (p % 2 == 0)
        return 0;

    return n;
}

inline W xor_0_to_n(W n)
{
    W mod = n % 4;

    if (mod == 0)
        return n;

    if (mod == 1)
        return 1;

    if (mod == 2)
        return n + 1;

    else
        return 0;
}

// rigid = non-interesting

// Find xor of all rigid numbers in range [0, n]
inline W xor_rigid_0_to_n(W n, W k, W i)
{
    W lowmask = ((((W)1ULL) << i) - (W)1);
    W highmask = ~lowmask;

    W low = n & lowmask;
    W high = n & highmask;

    W rep = (high >> i);

    if (k <= low)
    {
        rep++;
    }

    W xor_high = xor_0_to_n(rep - 1) << i;
    W xor_low = xor_power(k, rep);

    return xor_high | xor_low;
}

inline W xor_interesting_0_to_n(W n, W k, W i)
{
    return xor_0_to_n(n) ^ xor_rigid_0_to_n(n, k, i);
}

inline W xor_interesting_l_to_r(W l, W r, W k, W i)
{
    return (xor_interesting_0_to_n(r, k, i)
            ^ xor_interesting_0_to_n(l - 1, k, i));
}

// int main() {
//     std::ios_base::sync_with_stdio(false);

//     int t = next();

//     while (t--) {
//         W l = next<W>();
//         W r = next<W>();
//         W i = next<W>();
//         W k = next<W>();

//         cout << xor_interesting_l_to_r(l, r, k, i) << '\n';
//     }
// }


int main()
{
    // clang-format off
    W l     = 736784191255111734;
    W r     = 802505070715919462;
    W i     = 1;
    W k     = 0;
    // clang-format on
    cout << xor_interesting_l_to_r(l, r, k, i) << endl;
    return 0;
}




/*
10
367317916125644353 982847382819713718 30 770547887
736784191255111734 802505070715919462 1 0
838299857939206406 960571973791005929 12 2642
599466608693951125 657733523178034713 9 313
92535886075345595 244051677848187885 22 689537
457199476161564102 644517833182667067 13 7697
233449950930333943 609627132026128352 20 854823
558861894473780480 939042676645251843 0 0
668905436780490892 993862017430194795 11 370
748282204317883063 830310579949293699 14 3140


388658423
17644239000914539600
18446741082260245074
599466003975672981
92535886071151290
10505259441680
814414302862539824
0
0
17698442848124294899


388658423
17644239000914539600
18446741082260245074
599466003975672981
92535886071151290
10505259441680
814414302862539824
0
0
17698442848124294899


*/