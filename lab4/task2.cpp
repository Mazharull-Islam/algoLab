#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
#define inf 1e16


int main() {
    int t;
    cin >> t;
    int n, m;

    while(t--)
    {
        cin >> n >> m;
            vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
    }
    vector<int>s(n + 1);
    for(int i = 1; i <= n; i++)
    cin >> s[i];

    vector<vector<ll>> dist(n + 1, vector<ll>(n + 1, inf));
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    dist[1][1] = 0;
    pq.emplace(0ll, 1, 1);

    while(!pq.empty())
    {
        auto [d, u, k] = pq.top();
        pq.pop();

        if (d > dist[u][k]) continue;

        for (const auto& [v, w] : graph[u]) {
            ll newTime = d + w * 1ll * s[k];
            if (newTime < dist[v][k]) {
                dist[v][k] = newTime;
                pq.emplace(newTime, v, k);
            }

            ll switchTime = d + w * 1ll *s[u];
            if(switchTime < dist[v][u])
            {
                dist[v][u] = switchTime;
                pq.emplace(switchTime, v, u);
            }
         }
        }
        long long ans = inf;
        for(int i = 1; i <= n; i++)
        {
            ans = min(ans, dist[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
