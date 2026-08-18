#include <bits/stdc++.h>
using namespace std;

int MinPathSum(vector<vector<int>>& points) {
    int n = points.size();
    int m = points[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = points[0][0];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (i == 0 && j == 0)
                continue;

            int up = INT_MAX;
            int left = INT_MAX;

            if (i > 0)
                up = dp[i - 1][j];

            if (j > 0)
                left = dp[i][j - 1];

            dp[i][j] = points[i][j] + min(up, left);
        }
    }

    return dp[n - 1][m - 1];
}

int main() {

    vector<vector<int>> points = {
        {1, 4, 7},
        {2, 5, 1},
        {3, 6, 9}
    };

    cout << MinPathSum(points) << endl;

    return 0;
}