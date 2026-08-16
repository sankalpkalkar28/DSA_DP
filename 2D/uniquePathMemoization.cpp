#include <bits/stdc++.h>
using namespace std;

int ways(int i, int j, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if(i==0 && j==0) {
        return 1;
    }

    if(i<0 || j<0) return 0;

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    return dp[i][j] = (ways(i-1, j, points, dp) +
    ways(i, j-1, points, dp));
}

int ninjaTraining(int i, vector<vector<int>> points) {
    vector<vector<int>> dp(i, vector<int> (i, -1));
    return ways(i-1, i-1, points, dp);
}

int main() {
    vector<vector<int>> points = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int n = points.size();
    
    cout << ninjaTraining(n, points) << endl;  // Output: 210
    
    return 0;
}