#include <bits/stdc++.h>
using namespace std;

int unboundedKnapsack(int n, int W, vector<int>& val, vector<int>& wt) {

    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: only item 0 available
    for (int w = 0; w <= W; w++) {
        dp[0][w] = (w / wt[0]) * val[0];
    }

    for (int ind = 1; ind < n; ind++) {
        for (int w = 0; w <= W; w++) {

            // Not take
            int notTake = dp[ind - 1][w];

            // Take
            int take = 0;
            if (wt[ind] <= w) {
                take = val[ind] + dp[ind][w - wt[ind]];
            }

            dp[ind][w] = max(take, notTake);
        }
    }

    return dp[n - 1][W];
}

int main() {
    int n = 4;
    int W = 8;

    vector<int> wt = {2, 3, 4, 5};
    vector<int> val = {40, 50, 70, 80};

    cout << unboundedKnapsack(n, W, val, wt);

    return 0;
}
