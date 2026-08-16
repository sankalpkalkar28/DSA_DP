#include <bits/stdc++.h>
using namespace std;

int houseRobber(int n, vector<int> &arr, vector<int> &dp) {
    if(n==0) return arr[0];
    if(n<0) return 0;

    if(dp[n] != -1) {
        return dp[n];
    }

    return dp[n] = max(arr[n] + houseRobber(n-2, arr, dp), houseRobber(n-1, arr, dp));

}

int main() {
    vector<int> arr = {2,1,6,4,9,5};
    int n = arr.size();

    vector<int> temp1(n-1);
    vector<int> temp2(n-1);
    
    for(int i=0; i<n-1; i++) {
        temp1[i] = arr[i+1];
        temp2[i] = arr[i];
    }

    vector<int> dp1(n-1, -1);
    vector<int> dp2(n-1, -1);

    cout << max(houseRobber(n-2, temp1, dp1), houseRobber(n-2, temp2, dp2));    

    return 01;
}