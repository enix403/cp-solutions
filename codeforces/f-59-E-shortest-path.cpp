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
vvi adj_inp;

void dijk(vv<pi>& adj)
{
    int n = adj.size();

    vector<int> par(n, -1);
    vector<int> upmid(n, -1);
    vector<ll> dist(n, INF);
    min_heap<pi> q;

    dist[0] = 0;
    q.push({ 0 /*dist*/, 0 /*node*/ });

    while (!q.empty())
    {
        ll cur_dist = q.top().first;
        int v = q.top().second;
        q.pop();

        if (cur_dist > dist[v])
            continue;

        for (const auto& e : adj[v])
        {
            ll to = e.first;

            ll new_d = dist[v] + 1;
            if (new_d < dist[to])
            {
                dist[to] = new_d;
                par[to] = v;
                upmid[to] = e.second;
                q.push({ new_d, to });
            }
        }
    }

    n /= 2;
    int t = n - 1;

    if (dist[t + n] <= dist[t])
    {
        t += n;
    }

    if (dist[t] == INF)
    {
        cout << "-1\n";
        return;
    }

    vi path;
    int cur = t;
    while (cur != -1)
    {
        path.push_back(cur);
        if (upmid[cur] != -1)
            path.push_back(upmid[cur]);
        cur = par[cur];
    }

    cout << path.size() - 1 << '\n';

    allop(reverse, path);
    for (auto v : path)
    {
        if (v >= n)
            v -= n;

        cout << v + 1 << ' ';
    }

    cout << '\n';
}


int main()
{
    FAST_IO;

    cin >> n >> m >> k;
    adj_inp.assign(n, vi {});

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        if (a == b)
            continue;

        adj_inp[a].push_back(b);
        adj_inp[b].push_back(a);
    }

    vv<pi> adj(2 * n);

    {
        set<tuple<int, int, int>> fb;

        for (int i = 0; i < k; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;

            a--;
            b--;
            c--;

            fb.insert({ a, b, c });
        }


        // -------------------------

        // build square graph
        for (int a = 0; a < n; ++a)
        {
            for (auto b : adj_inp[a])
            {
                for (auto c : adj_inp[b])
                {
                    if (fb.find({ a, b, c }) == fb.end())
                    {
                        adj[a].emplace_back(c, b);
                    }
                }
            }
        }
    }


    for (int v = 0; v < n; ++v)
    {
        for (auto u : adj_inp[v])
        {
            adj[v].emplace_back(n + u, -1);
        }
    }

    dijk(adj);

    return 0;
}


/*
4 4 1
1 2
2 3
3 4
1 3
1 3 4

*/

/*

int main()
{
    FAST_IO;

    cout << numeric_limits<ll>::max() << endl;
    return 0;

    int n, m;
    cin >> n >> m;

    vector<vector<pll>> adj(n);

    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        a--;
        b--;

        if (a == b)
            continue;

        adj[a].push_back({ b, w });
        adj[b].push_back({ a, w });
    }

    dijkstra(adj);
}
*/
