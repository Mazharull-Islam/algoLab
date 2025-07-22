// ### Problem: Equal Money Distribution

// There are `n` people in a village, each holding a certain amount of money. Some pairs of people are connected by relations that allow them to transfer money back and forth between each other any number of times. Transactions must be **integer only**.
// One day, a wise person told them to redistribute their money so that **everyone ends up with exactly the same amount**. Your task is to determine whether it is possible for **each person** to have the **same amount of money**, given the constraints on who can transact with whom.
// ### Input Format

// * The first line contains a single integer `T` (1 ≤ T ≤ 100) — the number of test cases.
// For each test case:
// * The first line contains two integers `n` and `m` (2 ≤ n ≤ 1000, 0 ≤ m ≤ 10000):
//   * `n`: the number of people
//   * `m`: the number of relations
// * The second line contains `n` space-separated integers — the amount of money each person has.
// * The next `m` lines each contain two integers `u` and `v` (1 ≤ u, v ≤ n, u ≠ v), indicating that person `u` and person `v` can make transactions.
//   * No relation is repeated more than once.
// ### Output Format
// For each test case, print:
// Case i: Yes
// if it is possible for everyone to end up with the same amount of money, or:
// Case i: No

// otherwise.
// Here, `i` is the test case number starting from 1.
// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 3            | Case 1: Yes   |
// | 5 4          | Case 2: No    |
// | 1 0 1 1 2    | Case 3: No    |
// | 1 2          |               |
// | 2 3          |               |
// | 3 4          |               |
// | 4 5          |               |
// | 2 1          |               |
// | 5 10         |               |
// | 1 2          |               |
// | 4 2          |               |
// | 1 1 0 2      |               |
// | 1 2          |               |
// | 2 3          |               |


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

void dfs(int node, vector<vector<int>>&graph, vector<bool>visited, long long totalMoney,
    int& count, const vector<int>& money)
{
    visited[node] = true;
    totalMoney += money[node];
    count++;

    for(int neighbor : graph[node])
    {
     if(!visited[neighbor])
        {
            dfs(neighbor, graph , visited, totalMoney, count, money);
        }
    }

}

signed main()
{
    pre();

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> money(n);
        for (int i = 0; i < n; i++) {
            cin >> money[i];
        }

        vector<vector<int>> graph(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; // Convert to 0-based index
            v--; // Convert to 0-based index
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        bool canEqualize = true;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long totalMoney = 0;
                int count = 0;
                dfs(i, graph, visited, totalMoney, count, money);

                // Check if the total money can be evenly distributed
                if (totalMoney % count != 0) {
                    canEqualize = false;
                    break;
                }
            }
        }

        cout << "Case " << t << ": " << (canEqualize ? "Yes" : "No") << endl;
    }

    return 0;
}
