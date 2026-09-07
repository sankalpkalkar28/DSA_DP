#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cutRod(int price[], int n) {
        // dp[i][len] represents max profit considering cuts from i to n-1 for rod length len
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(price, n, 0, n, dp);
    }
    
    int solve(int price[], int n, int i, int len, vector<vector<int>>& dp) {
        // Base case: no more cuts possible or no rod length left
        if (len == 0 || i >= n) {
            return 0;
        }
        
        // Return if already computed
        if (dp[i][len] != -1) {
            return dp[i][len];
        }
        
        // Option 1: Don't cut at current length (move to next index)
        int notPick = solve(price, n, i + 1, len, dp);
        
        // Option 2: Cut at current length (i+1 because of 1-based indexing)
        int pick = 0;
        int currLen = i + 1;
        if (currLen <= len) {
            pick = price[i] + solve(price, n, i, len - currLen, dp);
        }
        
        // Store and return the maximum
        return dp[i][len] = max(pick, notPick);
    }
};

int main() {
    int n;
    cout << "Enter the length of the rod: ";
    cin >> n;
    
    int price[n];
    cout << "Enter the price array (price[i] = price of piece of length i+1): " << endl;
    for(int i = 0; i < n; i++) {
        cin >> price[i];
    }
    
    Solution obj;
    int maxProfit = obj.cutRod(price, n);
    
    cout << "\nMaximum profit that can be obtained: " << maxProfit << endl;
    
    return 0;
}