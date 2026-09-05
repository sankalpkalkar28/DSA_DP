#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                // ★ 3-LINE CORE UPDATE CODE ★
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                // ★ END OF 3-LINE UPDATE ★
            }
        }
        return dp[n][m];
    }
};

// Driver code
int main() {
    Solution sol;
    string s1 = "abcde", s2 = "ace";
    cout << "LCS Length: " << sol.longestCommonSubsequence(s1, s2) << endl; // Output: 3
    return 0;
}
git add . && git commit -m "feat: add LCS using Striver DP tabulation" && git push