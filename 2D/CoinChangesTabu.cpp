#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int n = coins.size();

    vector<vector<long long>> dp(
        n,
        vector<long long>(amount + 1, 0)
    );

    // Using only coin[0]
    for(int target = 0; target <= amount; target++) {

        if(target % coins[0] == 0)
            dp[0][target] = 1;
    }

    // Fill DP table
    for(int ind = 1; ind < n; ind++) {

        for(int target = 0; target <= amount; target++) {

            // Don't take
            long long notTake = dp[ind - 1][target];

            // Take
            long long take = 0;

            if(coins[ind] <= target) {

                // SAME index because unlimited coins
                take = dp[ind][target - coins[ind]];
            }

            dp[ind][target] = take + notTake;
        }
    }

    cout << dp[n - 1][amount] << endl;

    return 0;
}
