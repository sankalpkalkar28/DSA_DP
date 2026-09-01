#include <bits/stdc++.h>
using namespace std;

long long countWays(int ind, int amount,
                    vector<int>& coins,
                    vector<vector<long long>>& dp) {

    // Only one coin is available
    if(ind == 0) {
        if(amount % coins[0] == 0)
            return 1;

        return 0;
    }

    if(dp[ind][amount] != -1)
        return dp[ind][amount];

    // Don't take current coin
    long long notTake = countWays(
        ind - 1,
        amount,
        coins,
        dp
    );

    // Take current coin
    long long take = 0;

    if(coins[ind] <= amount) {
        take = countWays(
            ind,                         // SAME index
            amount - coins[ind],
            coins,
            dp
        );
    }

    return dp[ind][amount] = take + notTake;
}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 5;

    int n = coins.size();

    vector<vector<long long>> dp(
        n,
        vector<long long>(amount + 1, -1)
    );

    cout << countWays(
        n - 1,
        amount,
        coins,
        dp
    ) << endl;

    return 0;
}
