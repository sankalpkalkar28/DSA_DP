#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr) {

    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    int target = totalSum / 2;

    // dp[ind][target]
    vector<vector<bool>> dp(
        n,
        vector<bool>(target + 1, false)
    );

    // Target 0 is always possible
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Using only first element
    if(arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    // Fill DP table
    for(int ind = 1; ind < n; ind++) {

        for(int t = 1; t <= target; t++) {

            // Don't take
            bool notTake = dp[ind - 1][t];

            // Take
            bool take = false;

            if(arr[ind] <= t) {
                take = dp[ind - 1][t - arr[ind]];
            }

            dp[ind][t] = take || notTake;
        }
    }

    // Find minimum difference
    int mini = INT_MAX;

    for(int s1 = 0; s1 <= target; s1++) {

        if(dp[n - 1][s1]) {

            int s2 = totalSum - s1;

            int diff = abs(s1 - s2);

            mini = min(mini, diff);
        }
    }

    return mini;
}

int main() {

    vector<int> arr = {1, 2, 3, 4};

    cout << minSubsetSumDifference(arr) << endl;

    return 0;
}
