#include <bits/stdc++.h>
using namespace std;

int countPartitions(vector<int>& arr, int d) {

    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    // Impossible cases
    if(totalSum - d < 0)
        return 0;

    if((totalSum + d) % 2 != 0)
        return 0;

    int target = (totalSum + d) / 2;

    vector<vector<int>> dp(
        n,
        vector<int>(target + 1, 0)
    );

    // Base case
    if(arr[0] == 0) {
        dp[0][0] = 2;
    }
    else {
        dp[0][0] = 1;

        if(arr[0] <= target)
            dp[0][arr[0]] = 1;
    }

    // Fill DP table
    for(int ind = 1; ind < n; ind++) {

        for(int t = 0; t <= target; t++) {

            // Don't take
            int notTake = dp[ind - 1][t];

            // Take
            int take = 0;

            if(arr[ind] <= t) {
                take = dp[ind - 1][t - arr[ind]];
            }

            dp[ind][t] = take + notTake;
        }
    }

    return dp[n - 1][target];
}

int main() {

    vector<int> arr = {5, 2, 6, 4};

    int d = 3;

    cout << countPartitions(arr, d) << endl;

    return 0;
}
