#include <algorithm>
#include <bits/stdc++.h>
#include <limits>
#include <unistd.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;
const long long inf = numeric_limits<LL>::max();

LL dist[505][505];

void pre()
{
    fastio;


}

void solve(int tc)
{

}

int main()
{
    pre();

    int n, m, q;
    cin >> n >> m >> q;

    fill(&dist[0][0], &dist[n+1][n+1], inf);

    for(int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
     int a, b, c;
     cin >> a >> b >> c;
     dist[a][b] = min(dist[a][b], (LL) c);
     dist[b][a] = min(dist[b][a], (LL)c);
    }

    for(int k = 1; k <= n; k++)
    {
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (dist[i][k] < inf && dist[k][j] < inf )
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] == inf)
        {
            cout << -1 << endl;
        }else{
            cout << dist[a][b] << endl;
        }
    }

    return 0;
}
