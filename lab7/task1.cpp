// ### Problem: Minimum Coin Change

// You are given:

// * An integer `C` representing the **target amount** of money you want to make.
// * An array of `n` coin denominations, with an **infinite supply** of each coin.
// Your task is to compute the **minimum number of coins** required to make up the amount `C`. If it is **not possible** to make the amount using any combination of the coins, return `-1`.

// ### Input Format

// Each test case consists of **3 lines**:

// 1. A single integer `C` (0 ≤ C ≤ 10⁴) — the amount of change to make.
// 2. A single integer `n` (1 ≤ n ≤ 12) — the number of coin denominations.
// 3. A line with `n` space-separated integers `x₁, x₂, ..., xₙ` (1 ≤ xᵢ ≤ 2³¹−1) — the values of the available coin types.

// ---

// ### Output Format

// * Print a single integer — the **fewest number of coins** needed to make the amount `C`, or `-1` if it's not possible.
// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 11           | 3             |
// | 3            |               |
// | 1 2 5        |               |
// | 3            | -1            |
// | 1            |               |
// | 2            |               |
// | 0            | 0             |
// | 1            |               |
// | 1            |               |

#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

const int MAX_AMOUNT = 10000;
int dp[MAX_AMOUNT + 1];

int coinChange(int amount, int coins[], int n)
{
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;

    for (int i = 0; i < n; i++)
    {
        int coin = coins[i];
        for (int j = coin; j <= amount; j++)
        {
            if (dp[j - coin] != INT_MAX)
            {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

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

    int amount;
    cin >> amount;
    int n;
    cin >> n;
    int coins[n];

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    int result = coinChange(amount, coins, n);
    cout << result << endl;

    return 0;
}
