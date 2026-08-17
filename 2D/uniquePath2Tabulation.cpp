#include <bits/stdc++.h>
using namespace std;

int countPaths(vector<vector<int>>& points) {
    int n = points.size();
    int m = points[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // Blocked cell
            if (points[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }

            // Starting cell
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0;
            int left = 0;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = up + left;
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    vector<vector<int>> points = {
        {1, 4, 7},
        {2, -1, 8},
        {3, 6, 9}
    };

    cout << countPaths(points) << endl;

    return 0;
}