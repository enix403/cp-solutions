#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

#define all(v)       (v).begin(), (v).end()
#define rall(v)      (v).rbegin(), (v).rend()
#define allop(op, v) op(all(v))

#define ll   long long
#define ull  unsigned long long
#define pi   pair<int, int>
#define pll  pair<ll, ll>
#define umap unordered_map
#define uset unordered_set
#define vi   vector<int>
#define vll  vector<ll>
#define vvi  vector<vector<int>>
#define vvll vector<vector<ll>>

template<typename T>
using vv = vector<vector<T>>;

template<typename T>
using max_heap = priority_queue<T>;

template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

#define FAST_IO                   \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

/* --------------------- */

const ll INF = 1e15;

int n, m, k;

vv<tuple<int, ll, int>> adj;
vector<int> ei;
vector<ll> dist;

void dijkstra()
{
    ei.assign(n, -1);
    dist.assign(n, INF);

    int src = 0;
    dist[src] = 0;

    min_heap<tuple<ll, int, int>> q;
    q.push({ 0, 0, src });

    while (!q.empty())
    {
        auto cur_dist = get<0>(q.top());
        auto v = get<2>(q.top());

        q.pop();

        if (cur_dist > dist[v])
            continue;

        for (const auto& e : adj[v])
        {
            auto to = std::get<0>(e);
            auto w = std::get<1>(e);
            auto index = std::get<2>(e);

            ll new_d = dist[v] + w;
            if (tie(new_d, index) < tie(dist[to], ei[to]))
            {
                dist[to] = new_d;
                ei[to] = index;
                q.push({ new_d, index, to });
            }
        }
    }
}


int main()
{
    FAST_IO;

    cin >> n >> m >> k;

    adj.assign(n, {});

    for (int i = 0; i < m; ++i)
    {
        ll a, b, w;
        cin >> a >> b >> w;

        a--;
        b--;

        if (a == b)
            continue;

        adj[a].push_back({ b, w, -1 });
        adj[b].push_back({ a, w, -1 });
    }

    for (int i = 0; i < k; ++i)
    {
        ll b, w;
        cin >> b >> w;

        b--;

        ll a = 0;
        adj[a].push_back({ b, w, i });
        adj[b].push_back({ a, w, i });
    }

    dijkstra();

    int count = 0;

    for (const auto& e : adj[0])
    {
        auto to = get<0>(e);
        auto index = get<2>(e);

        if (index == -1)
            continue;

        if (ei[to] == index)
            continue;

        count++;
    }

    cout << count << '\n';
}
