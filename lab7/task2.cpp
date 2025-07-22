// ### Problem: Maximum Pages with Budget Constraint

// You are in a bookshop that sells `n` different books. Each book has a price and a number of pages. You want to buy books so that the **total price does not exceed** `x`. You can buy **each book at most once**.
// Your goal is to find the **maximum total number of pages** you can get while spending at most `x`.
// ### Input Format

// * The first line contains two integers `n` and `x` (1 ≤ n ≤ 1000, 1 ≤ x ≤ 10⁵):

//   * `n`: the number of books
//   * `x`: the maximum total price you are willing to pay
// * The second line contains `n` integers `h₁, h₂, ..., hₙ` (1 ≤ hᵢ ≤ 1000): the price of each book.
// * The third line contains `n` integers `s₁, s₂, ..., sₙ` (1 ≤ sᵢ ≤ 1000): the number of pages of each book.
// ### Output Format

// * Print a single integer — the maximum total number of pages you can buy without exceeding the total price `x`.
// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 4 10         | 13            |
// | 4 8 5 3      |               |
// | 5 12 8 1     |               |

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

int main()
{
    pre();

    int n, x;
    cin >> n >> x;

    int price[n], pages[n];


    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }


    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }


    int dp[x + 1] = {0};

    for (int i = 0; i < n; i++)
    {

        for (int j = x; j >= price[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - price[i]] + pages[i]);
        }
    }


    cout << dp[x] << endl;

    return 0;
}
