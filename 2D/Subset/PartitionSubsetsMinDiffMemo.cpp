#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {

    // Target 0 is always possible
    if(target == 0)
        return true;

    // Only one element available
    if(ind == 0)
        return arr[0] == target;

    // Already calculated
    if(dp[ind][target] != -1)
        return dp[ind][target];

    // Don't take current element
    bool notTake = subsetSumUtil(ind - 1, target, arr, dp);

    // Take current element
    bool take = false;

    if(arr[ind] <= target) {
        take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }

    return dp[ind][target] = take || notTake;
}

int minSubsetSumDifference(vector<int>& arr) {

    int n = arr.size();

    int totalSum = 0;

    for(int x : arr)
        totalSum += x;

    /*
        We only need to check subset sums
        from 0 to totalSum/2.
    */
    int target = totalSum / 2;

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int mini = INT_MAX;

    for(int s1 = 0; s1 <= target; s1++) {

        if(subsetSumUtil(n - 1, s1, arr, dp)) {

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
