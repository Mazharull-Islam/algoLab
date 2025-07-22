#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> pos(n);
        for (int i = 0; i < n; ++i) {
            cin >> pos[i];
        }

        // Preprocess: store positions with pheromone trail
        vector<int> trail_positions;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                trail_positions.push_back(pos[i]);
            }
        }

        long long total_cost = 0;

        // For each chamber with '0', find the closest '1'
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                int x = pos[i];
                // Binary search to find the closest pheromone position
                auto it = lower_bound(trail_positions.begin(), trail_positions.end(), x);
                long long min_dist = LLONG_MAX;

                if (it != trail_positions.end()) {
                    min_dist = min(min_dist, (long long)abs(x - *it));
                }
                if (it != trail_positions.begin()) {
                    --it;
                    min_dist = min(min_dist, (long long)abs(x - *it));
                }
                total_cost += min_dist;
            }
        }

        cout << total_cost << '\n';
    }
    return 0;
}
