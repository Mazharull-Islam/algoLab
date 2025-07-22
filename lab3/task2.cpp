// ### Problem: Journey to the Moon

// The member states of the UN are planning to send **two astronauts to the moon**. To ensure representation, the two astronauts must be from **different countries**.
// You are given a list of astronaut ID pairs, where each pair represents astronauts from the **same country**. Each astronaut belongs to **exactly one country** (but not all astronauts may appear in the input). Your task is to determine the **number of ways to choose a pair of astronauts from different countries**.
// ### Input Format
// * The first line contains two integers `n` and `p`:
//   * `n` (2 ≤ n ≤ 10⁵): the total number of astronauts.
//   * `p` (1 ≤ p ≤ 10⁴): the number of astronaut pairs that share the same nationality.
// * Each of the next `p` lines contains two space-separated integers `u` and `v` (0 ≤ u, v < n, u ≠ v), indicating that astronauts `u` and `v` are from the same country.
// ### Output Format
// * Print a single integer — the total number of valid pairs of astronauts that can be formed such that the two astronauts are from **different countries**.
// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 5 3          | 6             |
// | 0 1          |               |
// | 2 3          |               |
// | 0 4          |               |
// | 4 1          | 5             |
// | 0 2          |               |

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;



void pre()
{
    fastio;


}

void solve(int tc)
{

}

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited, int &count) {
    visited[node] = true;
    count++;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, count);
        }
    }
}

signed main()
{
    pre();

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p;
    cin >> n >> p;
    vector<vector<int>> graph(n);

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);
    vector<int> country_sizes;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int count = 0;
            dfs(i, graph, visited, count);
            country_sizes.push_back(count);
        }
    }


    long long total_pairs = (long long)n * (n - 1) / 2;
    long long same_country_pairs = 0;
    for (int size : country_sizes) {
        same_country_pairs += (long long)size * (size - 1) / 2;
    }
    cout << total_pairs - same_country_pairs << "\n";

    return 0;
}
