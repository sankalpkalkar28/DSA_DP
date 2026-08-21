#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j1, int j2, vector<vector<int>>& grid) {
        // Out of bounds
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
            return -1e9;

        // Last row
        if (i == n - 1) {
            if (j1 == j2)
                return grid[i][j1];

            return grid[i][j1] + grid[i][j2];
        }

        // Already calculated
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = -1e9;

        // Robot 1: -1, 0, +1
        // Robot 2: -1, 0, +1
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {

                int cherries;

                if (j1 == j2)
                    cherries = grid[i][j1];
                else
                    cherries = grid[i][j1] + grid[i][j2];

                cherries += solve(i + 1,
                                  j1 + dj1,
                                  j2 + dj2,
                                  grid);

                maxi = max(maxi, cherries);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(m, -1)
        ));

        return solve(0, 0, m - 1, grid);
    }
};

int main() {

    // Example grid
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5},
        {1, 2, 4, 1}
    };

    Solution obj;

    int ans = obj.cherryPickup(grid);

    cout << "Maximum cherries collected = " << ans << endl;

    return 0;
}
