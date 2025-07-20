#include <bits/stdc++.h>
using namespace std;

using LL = long long;

struct Edge {
    int u, v;
    LL cost;
    bool operator>(const Edge& other) const {
        return cost > other.cost;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) return false;
        if (rank[xr] < rank[yr]) swap(xr, yr);
        parent[yr] = xr;
        if (rank[xr] == rank[yr]) rank[xr]++;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    for (int i = 0; i < m; ++i) {
        int u, v;
        LL w;
        cin >> u >> v >> w;
        pq.push({u, v, w});
    }

    DSU dsu(n);
    LL total_cost = 0;
    int edges_used = 0;

    while (!pq.empty() && edges_used < n - 1) {
        Edge e = pq.top(); pq.pop();
        if (dsu.unite(e.u, e.v)) {
            total_cost += e.cost;
            edges_used++;
        }
    }

    if (edges_used != n - 1) {
        cout << "The graph is not connected. No spanning tree exists.\n";
    } else {
        cout << "Minimum Cost of Spanning Tree: " << total_cost << '\n';
    }

    return 0;
}
