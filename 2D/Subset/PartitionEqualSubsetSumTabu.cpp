#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();

    // dp[ind][target]
    // true = target can be formed using elements 0...ind
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Target 0 can always be formed by taking nothing
    for(int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Using only the first element
    if(arr[0] <= target) {
        dp[0][arr[0]] = true;
    }

    // Fill the table
    for(int ind = 1; ind < n; ind++) {

        for(int t = 1; t <= target; t++) {

            // Don't take arr[ind]
            bool notTake = dp[ind - 1][t];

            // Take arr[ind]
            bool take = false;

            if(arr[ind] <= t) {
                take = dp[ind - 1][t - arr[ind]];
            }

            dp[ind][t] = notTake || take;
        }
    }

    return dp[n - 1][target];
}

bool isPartition(vector<int>& arr) {
    int sum = 0;

    for(auto i : arr) {
        sum += i;
    }

    // Odd sum cannot be divided into two equal subsets
    if(sum % 2 != 0) {
        return false;
    }

    return isSubsetSum(arr, sum / 2);
}

int main() {

    vector<int> arr = {2, 3, 4, 3, 3, 5};

    cout << isPartition(arr) << endl;

    return 0;
}
