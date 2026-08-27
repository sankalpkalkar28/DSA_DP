#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base cases
    if(target == 0) return true;
    if(ind == 0) return arr[0] == target;
    
    // Check if already computed
    if(dp[ind][target] != -1) return dp[ind][target];
    
    // Not take current element
    bool notTake = subsetSumUtil(ind - 1, target, arr, dp);
    
    // Take current element (if possible)
    bool take = false;
    if(arr[ind] <= target) {
        take = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    }
    
    return dp[ind][target] = notTake || take;
}

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return subsetSumUtil(n - 1, target, arr, dp);
}

int main() {
    vector<int> arr = {2, 3, 7, 8, 10};
    int target = 11;
    
    if(isSubsetSum(arr, target)) {
        cout << "Subset with sum " << target << " exists!" << endl;
    } else {
        cout << "No subset with sum " << target << " exists!" << endl;
    }
    return 0;
}