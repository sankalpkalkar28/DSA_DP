#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int W, vector<int>& wt, vector<int>& val,
          vector<vector<int>>& dp) {

    // Base case
    if (ind == 0) {
        return (W / wt[0]) * val[0];
    }

    if (dp[ind][W] != -1)
        return dp[ind][W];

    // Don't take the current item
    int notTake = solve(ind - 1, W, wt, val, dp);

    // Take the current item
    int take = 0;

    if (wt[ind] <= W) {
        take = val[ind] + solve(ind, W - wt[ind], wt, val, dp);
    }

    return dp[ind][W] = max(take, notTake);
}

int main() {

    // Our input
    int N = 4;
    int W = 8;

    vector<int> wt = {2, 3, 4, 5};
    vector<int> val = {40, 50, 70, 80};

    vector<vector<int>> dp(N, vector<int>(W + 1, -1));

    int ans = solve(N - 1, W, wt, val, dp);

    cout << "Maximum value = " << ans << endl;

    return 0;
}
