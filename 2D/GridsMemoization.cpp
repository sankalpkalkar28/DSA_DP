#include <bits/stdc++.h>
using namespace std;

int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp) {
    // Base case: if we're at day 0
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }
    
    // If already computed
    if (dp[day][last] != -1) {
        return dp[day][last];
    }
    
    int maxi = 0;
    for (int task = 0; task < 3; task++) {
        if (task != last) {
            int merit = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, merit);
        }
    }
    
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    // dp[day][last] where last can be 0, 1, 2 (activities) or 3 (no previous activity)
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // Start from day n-1 with last = 3 (no previous activity restriction)
    return f(n - 1, 3, points, dp);
}

int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    int n = points.size();
    
    cout << ninjaTraining(n, points) << endl;  // Output: 210
    
    return 0;
}