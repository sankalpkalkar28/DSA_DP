#include <bits/stdc++.h>
using namespace std;

int countSubsets(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // Base case
    if(ind == 0) {

        // Special case when arr[0] = 0
        if(target == 0 && arr[0] == 0)
            return 2;

        if(target == 0 || target == arr[0])
            return 1;

        return 0;
    }

    if(dp[ind][target] != -1)
        return dp[ind][target];

    // Don't take
    int notTake = countSubsets(ind - 1, target, arr, dp);

    // Take
    int take = 0;

    if(arr[ind] <= target) {
        take = countSubsets(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take + notTake;
}

int targetSum(vector<int>& arr, int target) {

    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    // Impossible
    if(totalSum < abs(target))
        return 0;

    // (totalSum + target) must be even
    if((totalSum + target) % 2 != 0)
        return 0;

    int requiredSum = (totalSum + target) / 2;

    vector<vector<int>> dp(n, vector<int>(requiredSum + 1, -1));

    return countSubsets(n - 1, requiredSum, arr, dp);
}

int main() {

    vector<int> arr = {1, 1, 1, 1, 1};

    int target = 3;

    cout << targetSum(arr, target) << endl;

    return 0;
}
