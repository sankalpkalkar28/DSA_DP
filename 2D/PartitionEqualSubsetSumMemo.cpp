#include <bits/stdc++.h>
using namespace std;

bool solve(int i, int target, vector<int>& nums,
           vector<vector<int>>& dp) {

    if (target == 0)
        return true;

    if (i == 0)
        return nums[0] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    // Don't take
    bool notTake = solve(i - 1, target, nums, dp);

    // Take
    bool take = false;
    if (nums[i] <= target)
        take = solve(i - 1, target - nums[i], nums, dp);

    return dp[i][target] = take || notTake;
}

int minimumDifference(vector<int>& nums) {

    int n = nums.size();

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> dp(
        n, vector<int>(totalSum + 1, -1)
    );

    // Calculate all possible subset sums
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {

        if (solve(n - 1, s1, nums, dp)) {

            int s2 = totalSum - s1;

            // Difference between two subsets
            int diff = abs(s2 - s1);

            // Keep minimum difference
            static int ans = INT_MAX;
            ans = min(ans, diff);
        }
    }

    // Recalculate answer cleanly
    int ans = INT_MAX;

    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (solve(n - 1, s1, nums, dp)) {
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
