#include<bits/stdc++.h>/
using namespace std;

    int solve(int index, int capacity, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {

        // Base case
        if(index == 0) {
            if(wt[0] <= capacity)
                return val[0];

            return 0;
        }

        // Already calculated
        if(dp[index][capacity] != -1)
            return dp[index][capacity];

        // Not Take
        int notTake = solve(index - 1, capacity, wt, val, dp);

        // Take
        int take = 0;

        if(wt[index] <= capacity) {
            take = val[index] +
                   solve(index - 1,
                         capacity - wt[index],
                         wt, val, dp);
        }

        return dp[index][capacity] = max(take, notTake);
    }

    int main() {
        vector<int> val = {10, 40, 70, 20};
        vector<int> wt = {1, 4, 2, 6};
        
        int W = 7;
        int n = wt.size();

        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        cout << solve(n - 1, W, wt, val, dp) << endl;

        return 0;
    }