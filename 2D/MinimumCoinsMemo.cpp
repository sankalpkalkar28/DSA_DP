#include <bits/stdc++.h>
using namespace std;

int solve(int ind, int target, vector<int>& coins, vector<vector<int>>& dp) {
    // Base case
    if (ind == 0) {
        if (target % coins[0] == 0)
            return target / coins[0];

        return 1e9; // impossible
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    // Don't take the coin
    int notTake = solve(ind - 1, target, coins, dp);

    // Take the coin (can take it again)
    int take = 1e9;

    if (coins[ind] <= target)
        take = 1 + solve(ind, target - coins[ind], coins, dp);

    return dp[ind][target] = min(take, notTake);
}

int minimumCoins(vector<int>& coins, int amount) {
    int n = coins.size();

    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    int ans = solve(n - 1, amount, coins, dp);

    if (ans >= 1e9)
        return -1;

    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << minimumCoins(coins, amount);

    return 0;
}
