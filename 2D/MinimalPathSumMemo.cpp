#include <bits/stdc++.h>
using namespace std;

int ways(int i, int j, vector<vector<int>>& points, vector<vector<int>>& dp) {
    if(i==0 && j==0) {
        return points[0][0];
    }

    if(i<0 || j<0) return INT_MAX;

    if(dp[i][j] != -1) {
        return dp[i][j];
    }

    int up = ways(i-1, j, points, dp);
    int left = ways(i, j-1, points, dp);

    return dp[i][j] = points[i][j] + min(up, left);
}

int MinPathSum(int i, vector<vector<int>> points) {
    vector<vector<int>> dp(i, vector<int> (i, -1));
    return ways(i-1, i-1, points, dp);
}

int main() {
    vector<vector<int>> points = {
        {1, 4, 7},
        {2, 5, 1},
        {3, 6, 9}
    };
    int n = points.size();
    
    cout << MinPathSum(n, points) << endl;  
    
    return 0;
}