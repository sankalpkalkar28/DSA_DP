#include <bits/stdc++.h>
using namespace std;

int minimumDifference(vector<int>& nums) {
    int n = nums.size();

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // dp[i][target] = whether target sum is possible
    // using elements from 0 to i
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Sum 0 is always possible
    dp[0][0] = true;

    // Using first element
    if (nums[0] <= totalSum) {
        dp[0][nums[0]] = true;
    }

    // Fill DP table
    for (int i = 1; i < n; i++) {
        for (int target = 0; target <= totalSum; target++) {

            // Do not take nums[i]
            bool notTake = dp[i - 1][target];

            // Take nums[i]
            bool take = false;

            if (nums[i] <= target) {
                take = dp[i - 1][target - nums[i]];
            }

            dp[i][target] = take || notTake;
        }
    }

    // Find minimum difference
    int ans = INT_MAX;

    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1]) {
            int s2 = totalSum - s1;
            ans = min(ans, abs(s2 - s1));
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {1, 2, 3, 9};

    cout << "Minimum absolute difference: "
         << minimumDifference(nums) << endl;

    return 0;
}
