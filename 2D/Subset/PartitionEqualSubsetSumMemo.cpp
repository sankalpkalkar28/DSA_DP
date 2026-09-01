#include <bits/stdc++.h>
using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);

    if(dp[ind][target] != -1) return dp[ind][target];

    bool notTake = subsetSumUtil(ind-1, target, arr, dp);

    bool take = false;
    if(arr[ind] <= target) {
        take = subsetSumUtil(ind-1, target-arr[ind], arr, dp);
    }

    return dp[ind][target] = notTake || take;
}

bool isSubsetSum(vector<int>& arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return subsetSumUtil(n - 1, target, arr, dp);
}

bool isPartition(vector<int>& arr) {
    int sum = 0;
    for(auto i: arr) sum += i;

    if(sum % 2 != 0) return false; 

    return isSubsetSum(arr, sum/2);
}

int main() {
    vector<int> arr = {2, 3, 4, 3, 3, 5};
    
    cout << isPartition(arr) << endl;
    return 0;
}