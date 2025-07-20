#include<iostream>
#include<vector>


using namespace std;
using ll = long long;
#define inf 10e16

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, m;
    cin >> n >> m ;
    vector<int>u(m), v(m);
    vector<ll>w(m);

    for (ll i = 0; i < m; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    vector<ll> dist(n + 1, 0);
    bool negCycle = true;

    for (ll i = 1; i <= n; i++)
    {
        for(ll j = 0; j < m; j++)
        {
            if(dist[v[j]] > dist[u[j]] + w[j] )
            {
                dist[v[j]] = dist[u[j]] + w[j];
                if(i == n)
                negCycle = true;
            }
        }
    }

    if(negCycle)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    

    return 0;
}
