#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
using PLL = pair<LL, LL>;
using TLLL = tuple<LL, LL, LL>;

using Neighbor = PLL; // first = node, second = weight
using Graph = vector<vector<Neighbor>>;

void mstPrim(Graph& graph, vector<LL>& dist, vector<int>& parent)
{
    int n = graph.size();

    priority_queue<TLLL, vector<TLLL>, greater<TLLL>> pq; // weight, node, parent
    pq.push({0, 0, -1});

    while (!pq.empty())
    {
        auto [d1, x, p] = pq.top();
        pq.pop();

        if (dist[x] != -1) continue;
        dist[x] = d1;
        parent[x] = p;

        for (auto [y, d2] : graph[x])
        {
            if (dist[y] != -1) continue;
            pq.push({d2, y, x});
        }
    }
}

void pre()
{
    fastio;
}

void solve(int tc)
{
    int n, m;
    cin >> n >> m;

    Graph graph(n);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        LL c;
        cin >> a >> b >> c;
        a--, b--; // 0-indexing
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    vector<LL> dist(n, -1);
    vector<int> parent(n, -1);

    mstPrim(graph, dist, parent);

    LL totalCost = 0;
    for (int i = 0; i < n; ++i)
    {
        if (dist[i] == -1)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }
        totalCost += dist[i];
    }

    cout << totalCost << "\n";
}

int main()
{
    pre();
    int tc = 1;
    for (int i = 1; i <= tc; ++i)
    {
        solve(i);
    }
    return 0;
}
