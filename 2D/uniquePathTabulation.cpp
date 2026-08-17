#include <bits/stdc++.h>
using namespace std;

int UniquePath(int n,int m) {

    vector<vector<int>> dp(n, vector<int>(m, 0));

    dp[0][0] = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(i==0 && j==0) continue;

            int up = 0;
            int left = 0;

            if(i>0) up = dp[i-1][j];
            if(j>0) left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }
        
    return dp[n-1][m-1];
}

int main() {
    int n = 3;
    int m = 3;
    
    cout << UniquePath(n, m) << endl;
    
    return 0;
}