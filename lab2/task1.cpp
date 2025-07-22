// You are given a container filled with a limited amount of water. The container can hold at most `x` liters of water.
// You are also given `n` empty bottles, each with a certain capacity. You want to fill as many bottles as possible using the water in the container, such that **each bottle is completely filled**.
// Your task is to determine the **maximum number of bottles** you can completely fill.

// ### Input Format

// * The first line contains a single integer `t` (1 ≤ t ≤ 10⁵) — the number of test cases.
// * For each test case:

//   * The first line contains two integers `n` and `x`

//     * `n` (1 ≤ n ≤ 10⁴): number of bottles
//     * `x` (1 ≤ x ≤ 10⁹): total capacity of the water container (in liters)
//   * The second line contains `n` space-separated integers `a₁, a₂, ..., aₙ`

//     * (1 ≤ aᵢ ≤ 10⁹): the capacity of each bottle

// Note: The sum of all `n` over all test cases does not exceed 10⁵.

// ### Output Format

// For each test case, print a single integer in a new line — the maximum number of bottles you can completely fill.

// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 3            | 4             |
// | 5 10         | 2             |
// | 2 3 4 5 1    | 0             |
// | 4 7          |               |
// | 5 3 4 2      |               |
// | 3 5          |               |
// | 6 7 8        |               |


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

signed main()
{
    pre();
    int t;
 cin >> t;
 while (t--) {
 long long n, x;
 cin >> n >> x;
 vector<int> a(n);
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 sort(a.begin(), a.end());
 long long count = 0;
 for (int i = 0; i < n; i++) {
 if (x >= a[i]) {
 x -= a[i];
 count++;
 } else {
 break;
 }
 }
 cout << count << endl;
 }
 return 0;

}
