#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
#define inf 1e16

void dikjstra(int n, const vector<vector<pair<int, int>>> &graph, vector<ll>& delays)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    delays[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        ll currentWeight = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();

        if (currentWeight > delays[currentNode])
            continue;
        for (const auto& edge : graph[currentNode])
        {
            int nextNode = edge.first;
            int weight = edge.second;

            if (delays[currentNode] + weight < delays[nextNode])
            {
                delays[nextNode] = delays[currentNode] + weight;
                pq.push({delays[nextNode], nextNode});
            }
        }
    }
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll a, b, c;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vector<ll> delays(n + 1, inf);
    dikjstra(n , graph, delays);

    for (ll i = 1; i <= n; i++)
    {
        cout << delays[i] << " ";
    }
    cout << endl;
    return 0;
    
    
}
