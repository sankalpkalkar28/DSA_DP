#include <bits/stdc++.h>
using namespace std;

bool subsetSumToK(int n, int k, vector<int>& arr) {

    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // We can always make sum 0
    dp[0][0] = true;

    // We can make arr[0] using the first element
    if (arr[0] <= k)
        dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {

        for (int target = 1; target <= k; target++) {

            // Don't take arr[i]
            bool notTake = dp[i - 1][target];

            // Take arr[i]
            bool take = false;

            if (arr[i] <= target)
                take = dp[i - 1][target - arr[i]];

            dp[i][target] = take || notTake;
        }
    }

    return dp[n - 1][k];
}

int main() {

    vector<int> arr = {1, 2, 3, 4};
    int k = 4;

    cout << subsetSumToK(arr.size(), k, arr);

    return 0;
}
