#include <bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points) {
    // dp[day][last] = max merit points up to this day
    // last can be 0, 1, 2 (previous day's activity) or 3 (no previous activity)
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    // Base case: Day 0
    dp[0][0] = max(points[0][1], points[0][2]);  // if last was 0, do 1 or 2
    dp[0][1] = max(points[0][0], points[0][2]);  // if last was 1, do 0 or 2
    dp[0][2] = max(points[0][0], points[0][1]);  // if last was 2, do 0 or 1
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});  // no restriction
    
    // Fill the DP table
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int merit = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], merit);
                }
            }
        }
    }
    
    return dp[n - 1][3];  // max merit on last day with no restriction
}

int main() {
    int n = 3;
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90}
    };
    
    cout << ninjaTraining(n, points) << endl;  // Output: 210
    
    return 0;
}