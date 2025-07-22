// ### Problem: Dot Product Minimization

// You are given two vectors `a` and `b`, each containing `n` integers. You are allowed to rearrange the elements of each vector in any order. Your task is to find such rearrangements that **minimize the dot product** of the two vectors.
// Formally, for two vectors:
// a = (a₁, a₂, ..., aₙ)
// b = (b₁, b₂, ..., bₙ)
// Find permutations π and σ of `{1, 2, ..., n}` such that the value of:
// ∑ (from i = 1 to n) of a[π(i)] * b[σ(i)] is **minimized**.

// ### Input Format

// * The first line contains a single integer `t` (1 ≤ t ≤ 10⁴) — the number of test cases.
// * For each test case:

//   * The first line contains a single integer `n` (1 ≤ n ≤ 10⁵) — the size of the vectors.
//   * The second line contains `n` space-separated integers `a₁, a₂, ..., aₙ` (|aᵢ| ≤ 10⁹) — the elements of the first vector.
//   * The third line contains `n` space-separated integers `b₁, b₂, ..., bₙ` (|bᵢ| ≤ 10⁹) — the elements of the second vector.

// Note: The sum of all `n` over all test cases does not exceed 10⁵.
// ### Output Format

// For each test case, print a single integer — the **minimum possible dot product** after rearranging the vectors.


// ### Sample Input and Output

// | Sample Input                            | Sample Output |
// | --------------------------------------- | ------------- |
// | 4                                       | -25           |
// | 3                                       | 60            |
// | 1 3 -5                                  | -55           |
// | -2 4 1                                  | 5000000000000 |
// | 4                                       |               |
// | 1 2 3 4                                 |               |
// | 5 6 7 8                                 |               |
// | 5                                       |               |
// | -1 -2 -3 -4 -5                          |               |
// | 5 4 3 2 1                               |               |
// | 5                                       |               |
// | 1000000 1000000 1000000 1000000 1000000 |               |
// | 1000000 1000000 1000000 1000000 1000000 |               |

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
           int n;
           cin >> n;
           vector<int> a(n), b(n);
           for (int i = 0; i < n; i++) {
               cin >> a[i];
           }
           for (int i = 0; i < n; i++) {
               cin >> b[i];
           }
           sort(a.begin(), a.end());
           sort(b.begin(), b.end(), greater<int>());

           long long dot_product = 0;
           for (int i = 0; i < n; i++) {
               dot_product += static_cast<long long>(a[i]) * b[i];
           }
           cout << dot_product << endl;
       }
       return 0;
}
