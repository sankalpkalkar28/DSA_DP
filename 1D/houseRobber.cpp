#include <bits/stdc++.h>
using namespace std;

int houseRobber(int n, vector<int> &arr, vector<int> &dp) {
    if(n==0) return arr[n];
    if (n<0) return 0;

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = max(arr[n] + houseRobber(n-2, arr, dp), houseRobber(n-1, arr, dp));

    return dp[n];
}

int main() {
    vector<int> arr = {2,1,4,9};
    int n = arr.size();
    vector<int> dp(n, -1);
    cout << houseRobber(n-1, arr, dp);
    return 0;
}