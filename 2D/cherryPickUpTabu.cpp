#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
        {1, 2, 4, 1}
    };

    int n = grid.size();
    int m = grid[0].size();

    // dp[i][j1][j2]
    vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(m, 0))
    );

    // Base case: last row
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {

            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] =
                    grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Fill from bottom to top
    for (int i = n - 2; i >= 0; i--) {

        for (int j1 = 0; j1 < m; j1++) {

            for (int j2 = 0; j2 < m; j2++) {

                int maxi = -1e9;

                // Robot 1: -1, 0, +1
                // Robot 2: -1, 0, +1
                for (int dj1 = -1; dj1 <= 1; dj1++) {

                    for (int dj2 = -1; dj2 <= 1; dj2++) {

                        int value;

                        // Current row cherries
                        if (j1 == j2)
                            value = grid[i][j1];
                        else
                            value = grid[i][j1] + grid[i][j2];

                        // Check next positions
                        if (j1 + dj1 >= 0 && j1 + dj1 < m &&
                            j2 + dj2 >= 0 && j2 + dj2 < m) {

                            value += dp[i + 1][j1 + dj1][j2 + dj2];

                            maxi = max(maxi, value);
                        }
                    }
                }

                dp[i][j1][j2] = maxi;
            }
        }
    }

    // Robot 1 starts at column 0
    // Robot 2 starts at column m-1
    cout << dp[0][0][m - 1] << endl;

    return 0;
}
