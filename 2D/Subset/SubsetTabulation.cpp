#include <bits/stdc++.h>
using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4};
    int target = 7;

    int n = arr.size();

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Target = 0 is always possible
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    // Using only first element
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    // Fill DP table
    for (int i = 1; i < n; i++) {

        for (int t = 1; t <= target; t++) {

            // Don't take
            bool notTake = dp[i - 1][t];

            // Take
            bool take = false;

            if (arr[i] <= t)
                take = dp[i - 1][t - arr[i]];

            dp[i][t] = take || notTake;
        }
    }

    if (dp[n - 1][target])
        cout << "Subset exists";
    else
        cout << "Subset does not exist";

    return 0;
}
