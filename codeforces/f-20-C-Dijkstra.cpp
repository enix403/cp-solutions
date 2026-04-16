#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define ll     long long
#define pii    pair<int, int>
#define pil    pair<int, long>
#define pli    pair<ll, int>
#define pll    pair<ll, ll>

const ll INF = 1e15;

void dijkstra(vector<vector<pair<int, ll>>>& adj)
{
    int n = adj.size();

    vector<ll> dist(n, INF);
    vector<int> par(n, -1);

    using Edge = pli;
    priority_queue<Edge, vector<Edge>, greater<Edge>> q;

    dist[0] = 0;
    q.push({ 0 /*dist*/, 0 /*node*/ });

    while (!q.empty())
    {
        ll cur_dist = q.top().first;
        int v = q.top().second;
        q.pop();

        if (cur_dist > dist[v])
            continue;

        if (v == n - 1)
            break;

        for (const auto& e : adj[v])
        {
            int to = e.first;
            ll w = e.second;

            ll new_d = dist[v] + w;
            if (new_d < dist[to])
            {
                dist[to] = new_d;
                par[to] = v;
                q.push({ new_d, to });
            }
        }
    }

    if (dist[n - 1] == INF)
    {
        cout << "-1\n";
        return;
    }

    vector<int> path;
    int cur = n - 1;
    while (cur != -1)
    {
        path.push_back(cur);
        cur = par[cur];
    }

    reverse(all(path));

    for (auto v : path)
        cout << v + 1 << ' ';

    cout << '\n';
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> adj(n);

    auto add_edge = [&](int a, int b, ll w) {
        auto& list = adj[a];
        list.push_back({ b, w });
    };

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
