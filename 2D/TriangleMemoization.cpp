#include <bits/stdc++.h>
using namespace std;

int ways(int i, int j, int n,
         vector<vector<int>>& points,
         vector<vector<int>>& dp) {

    // Last row
    if (i == n - 1)
        return points[i][j];

    // Already calculated
    if (dp[i][j] != -1)
        return dp[i][j];

    // Move down
    int d = points[i][j] + ways(i + 1, j, n, points, dp);

    // Move diagonally
    int dg = points[i][j] + ways(i + 1, j + 1, n, points, dp);

    return dp[i][j] = min(d, dg);
}

int Triangle(vector<vector<int>>& points) {

    int n = points.size();

    vector<vector<int>> dp(n, vector<int>(n, -1));

    return ways(0, 0, n, points, dp);
}

int main() {

    vector<vector<int>> points = {
        {1},
        {2, 8},
        {3, 6, 9},
        {6, 5, 1, 7}
    };

    cout << Triangle(points) << endl;

    return 0;
}