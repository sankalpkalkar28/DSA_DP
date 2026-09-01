#include <bits/stdc++.h>
using namespace std;

int targetSum(vector<int>& arr, int target) {

    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    // Impossible case
    if(totalSum < abs(target))
        return 0;

    // Required subset sum must be integer
    if((totalSum + target) % 2 != 0)
        return 0;

    int requiredSum = (totalSum + target) / 2;

    vector<vector<int>> dp(
        n,
        vector<int>(requiredSum + 1, 0)
    );

    // Base case
    if(arr[0] == 0) {
        dp[0][0] = 2;
    }
    else {
        dp[0][0] = 1;

        if(arr[0] <= requiredSum)
            dp[0][arr[0]] = 1;
    }

    // Fill DP table
    for(int ind = 1; ind < n; ind++) {

        for(int sum = 0; sum <= requiredSum; sum++) {

            // Don't take
            int notTake = dp[ind - 1][sum];

            // Take
            int take = 0;

            if(arr[ind] <= sum) {
                take = dp[ind - 1][sum - arr[ind]];
            }

            dp[ind][sum] = take + notTake;
        }
    }

    return dp[n - 1][requiredSum];
}

int main() {

    vector<int> arr = {1, 1, 1, 1, 1};

    int target = 3;

    cout << targetSum(arr, target) << endl;

    return 0;
}
