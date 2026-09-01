#include <bits/stdc++.h>
using namespace std;

int countSubsets(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // If target becomes 0, one subset is found:
    // the subset containing nothing more.
    if(target == 0)
        return 1;

    // If only first element is available
    if(ind == 0)
        return (arr[0] == target);

    // Already calculated
    if(dp[ind][target] != -1)
        return dp[ind][target];

    // Don't take current element
    int notTake = countSubsets(ind - 1, target, arr, dp);

    // Take current element
    int take = 0;

    if(arr[ind] <= target) {
        take = countSubsets(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take + notTake;
}

int findWays(vector<int>& arr, int k) {

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return countSubsets(n - 1, k, arr, dp);
}

int main() {

    vector<int> arr = {1, 2, 2, 3};
    int k = 3;

    cout << findWays(arr, k) << endl;

    return 0;
}
