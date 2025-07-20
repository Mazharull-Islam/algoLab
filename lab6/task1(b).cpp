#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
using TLLL = tuple<LL, LL, LL>;
using Graph = vector<TLLL>; // u, v, weight

struct DSU
{
    vector<int> parent, depth;

    DSU(int n) : parent(n), depth(n)
    {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int getRoot(int v)
    {
        if (parent[v] == v) return v;
        return parent[v] = getRoot(parent[v]);
    }

    void unionSets(int a, int b)
    {
        a = getRoot(a);
        b = getRoot(b);
        if (a == b) return;
        if (depth[a] < depth[b]) swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b]) depth[a]++;
    }

    bool isSameRoot(int a, int b)
    {
        return getRoot(a) == getRoot(b);
    }
};

bool comp(TLLL e1, TLLL e2)
{
    return get<2>(e1) < get<2>(e2);
}

void mstKruskal(int n, Graph& graph, Graph& tree)
{
    sort(graph.begin(), graph.end(), comp);
    DSU dsu(n);

    for (auto [u, v, w] : graph)
    {
        if (!dsu.isSameRoot(u, v))
        {
            dsu.unionSets(u, v);
            tree.push_back({u, v, w});
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

    Graph graph;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        LL c;
        cin >> a >> b >> c;
        a--, b--; // 0-indexed
        graph.push_back({a, b, c});
    }

    Graph tree;
    mstKruskal(n, graph, tree);

    if (tree.size() < n - 1)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    LL totalCost = 0;
    for (auto [u, v, w] : tree)
        totalCost += w;

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
