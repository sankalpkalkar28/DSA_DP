#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int knapsackUtil(int ind, int W, const vector<int>& wt, const vector<int>& val, vector<vector<int>>& dp) {
        // Base case: at the first item (index 0)
        if (ind == 0) {
            if (wt[0] <= W) return val[0];
            return 0;
        }

        // Return cached result if already computed
        if (dp[ind][W] != -1) return dp[ind][W];

        // Choice 1: Do not pick the current item
        int notTake = 0 + knapsackUtil(ind - 1, W, wt, val, dp);

        // Choice 2: Pick the current item (if capacity permits)
        int take = -1e9;
        if (wt[ind] <= W) {
            take = val[ind] + knapsackUtil(ind - 1, W - wt[ind], wt, val, dp);
        }

        // Memoize and return max value
        return dp[ind][W] = max(take, notTake);
    }

public:
    int knapsack(vector<int>& wt, vector<int>& val, int n, int W) {
        // Create DP table initialized with -1
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        return knapsackUtil(n - 1, W, wt, val, dp);
    }
};

int main() {
    // Sample Test Case
    vector<int> wt = {1, 2, 4, 5};   // Item weights
    vector<int> val = {5, 4, 8, 6};  // Item values
    int W = 5;                       // Knapsack capacity
    int n = wt.size();              // Number of items

    Solution sol;
    int maxProfit = sol.knapsack(wt, val, n, W);

    cout << "=== 0/1 Knapsack (Memoization) ===" << endl;
    cout << "Number of items: " << n << endl;
    cout << "Knapsack Capacity: " << W << endl;
    cout << "Maximum Value Obtained: " << maxProfit << endl;

    return 0;
}