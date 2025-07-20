#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
#define inf 1e16

void dikjstra(int n, const vector<vector<pair<int, int>>> &graph, vector<ll>& delays, vector<int>&parent, int source)
{
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    delays[source] = 0;
    pq.push({0, source});

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
                parent[nextNode] = currentNode;
                pq.push({delays[nextNode], nextNode});
            }
        }
    }
}

void printPath(int source, int target, const vector<int>& parent)
{
    vector<int> path;
    int current = target;
    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }
    reverse(path.begin(), path.end()); //What it means??

    if(path.front() != source)
    {
        cout << -1 << endl;
        return;
    }
    
    cout << path.size() - 1 << endl;
    for(int i = 0; i + 1 < path.size(); i++)
    {
        cout << path[i] << " " << path[i + 1] << endl;
    }

}

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    int a, b, c;
    vector<vector<pair<int, int>>> graph(n + 1);

    for (ll i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
    }
    vector<ll> delays(n + 1, inf);
    vector<int> parent(n + 1 , -1);
    dikjstra(n , graph, delays,parent, s);

    if(delays[t] == inf)
    {
        cout << -1 << endl;
        return 0;
    }

    else{
        cout << delays[t] << endl;
        printPath(s, t, parent);
    }

    return 0;
    
    
}
