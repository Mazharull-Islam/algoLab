#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

struct Beacon {
    int x, y, r;
};

bool isInRange(const Beacon& a, const Beacon& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long distSquared = dx * dx + dy * dy;
    return distSquared <= 1LL * a.r * a.r;
}

void bfs(int start, const vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Beacon> beacons(n);
    for (int i = 0; i < n; ++i) {
        cin >> beacons[i].x >> beacons[i].y >> beacons[i].r;
    }

 
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && isInRange(beacons[i], beacons[j])) {
                graph[i].push_back(j);
            }
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        --a; --b; 

        vector<bool> visited(n, false);
        bfs(a, graph, visited);

        if (visited[b]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
