#include <bits/stdc++.h>
using namespace std;

bool solve(int index, int target, vector<int>& arr,
           vector<vector<int>>& dp) {

    if (target == 0)
        return true;

    if (index == 0)
        return arr[0] == target;

    if (dp[index][target] != -1)
        return dp[index][target];

    // Don't take
    bool notTake = solve(index - 1, target, arr, dp);

    // Take
    bool take = false;

    if (arr[index] <= target)
        take = solve(index - 1, target - arr[index], arr, dp);

    return dp[index][target] = take || notTake;
}

int main() {

    vector<int> arr = {1, 2, 3, 4};
    int target = 7;

    int n = arr.size();

    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    if (solve(n - 1, target, arr, dp))
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}
