// variable starting path and endint path

#include <bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<vector<int>>& matrix,
      vector<vector<int>>& dp) {

    int n = matrix.size();
    int m = matrix[0].size();

    // Out of bounds
    if (j < 0 || j >= m)
        return -1e9;

    // First row
    if (i == 0)
        return matrix[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = f(i - 1, j, matrix, dp);

    int leftDiagonal = f(i - 1, j - 1, matrix, dp);

    int rightDiagonal = f(i - 1, j + 1, matrix, dp);

    return dp[i][j] =
        matrix[i][j] +
        max({up, leftDiagonal, rightDiagonal});
}

int getMaxPathSum(vector<vector<int>>& matrix) {

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = -1e9;

    // Last row: we can end at ANY column
    for (int j = 0; j < m; j++) {
        ans = max(ans, f(n - 1, j, matrix, dp));
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