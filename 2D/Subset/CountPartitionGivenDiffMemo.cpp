#include <bits/stdc++.h>
using namespace std;

int countSubsets(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // Base case
    if(ind == 0) {

        // If arr[0] is 0 and target is 0,
        // there are 2 choices:
        // take 0 OR don't take 0
        if(target == 0 && arr[0] == 0)
            return 2;

        // Either take arr[0] or take nothing
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

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return countSubsets(n - 1, target, arr, dp);
}

int main() {

    vector<int> arr = {5, 2, 6, 4};

    int d = 3;

    cout << countPartitions(arr, d) << endl;

    return 0;
}
