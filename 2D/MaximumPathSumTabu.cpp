#include <bits/stdc++.h>
using namespace std;

int getMaxPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    // dp[i][j] represents maximum path sum to reach cell (i,j)
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize first row
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }

    // Fill the dp table row by row
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // From directly above
            int up = dp[i-1][j];
            
            // From upper-left diagonal
            int leftDiagonal = (j > 0) ? dp[i-1][j-1] : -1e9;
            
            // From upper-right diagonal
            int rightDiagonal = (j < m-1) ? dp[i-1][j+1] : -1e9;
            
            // Take maximum of the three paths
            dp[i][j] = matrix[i][j] + max({up, leftDiagonal, rightDiagonal});
        }
    }

    // Find the maximum value in the last row
    int ans = -1e9;
    for (int j = 0; j < m; j++) {
        ans = max(ans, dp[n-1][j]);
    }

    return ans;
}

int main() {

    vector<vector<int>> matrix = {
        {1, 4, 7},
        {20, 50, 1},
        {3, 6, 92}
    };

    cout << getMaxPathSum(matrix) << endl;

    return 0;
}