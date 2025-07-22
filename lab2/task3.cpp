// ### Problem: Plan It Right

// You are an event planner hired to organize a series of activities for a group of tourists visiting a city. You are given a list of `n` activities, each with a **start time** and an **end time**. A tourist can participate in an activity only if they are not already engaged in another one at that time.
// Your goal is to select a **subset of non-overlapping activities** such that the tourists can attend the **maximum number of activities**.
// ### Input Format
// * The first line contains a single integer `t` (1 ≤ t ≤ 10⁴) — the number of test cases.
// * For each test case:

//   * The first line contains a single integer `n` (1 ≤ n ≤ 10⁵) — the number of activities.
//   * The second line contains `n` space-separated integers `s₁, s₂, ..., sₙ` (1 ≤ sᵢ ≤ 10⁹) — the start times of the activities.
//   * The third line contains `n` space-separated integers `e₁, e₂, ..., eₙ` (1 ≤ eᵢ ≤ 10⁹, sᵢ ≤ eᵢ) — the end times of the activities.
// Note: The sum of all `n` over all test cases does not exceed 10⁵.
// ### Output Format
// For each test case, print a single integer — the **maximum number of non-overlapping activities** that the tourists can attend.

// ### Sample Input and Output

// | Sample Input | Sample Output |
// | ------------ | ------------- |
// | 5            | 3             |
// | 4            | 2             |
// | 0 5 1 3      | 2             |
// | 6 7 2 4      | 2             |
// | 3            |               |
// | 1 4 6        |               |
// | 5 7 10       |               |
// | 6            |               |
// | 3 8 2 1 5 3  |               |
// | 9 9 5 4 9 6  |               |
// | 5            |               |
// | 1 2 3 1 4    |               |
// | 10 10 5 2 5  |               |
// | 3            |               |
// | 1 6 4        |               |
// | 5 10 7       |               |

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
using LL = long long;

struct Activity {
    int start;
    int end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(vector<Activity>& activities) {
    sort(activities.begin(), activities.end(), compare);

    int count = 0;
    int lastEndTime = -1;
    for (const auto& activity : activities) {

        if (activity.start >= lastEndTime) {
            count++;
            lastEndTime = activity.end;
        }
    }

    return count;
}



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

           vector<Activity> activities(n);
           vector<int> startTimes(n);
           vector<int> endTimes(n);

           for (int i = 0; i < n; i++) {
               cin >> startTimes[i];
           }

           for (int i = 0; i < n; i++) {
               cin >> endTimes[i];
           }

           for (int i = 0; i < n; i++) {
               activities[i] = {startTimes[i], endTimes[i]};
           }


           int result = maxActivities(activities);
           cout << result << endl;
       }

       return 0;
}
