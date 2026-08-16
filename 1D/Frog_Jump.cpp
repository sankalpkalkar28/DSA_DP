#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &heights, vector<int> &dp) {
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];

    int left = f(ind-1, heights, dp) + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;

    if(ind > 1) right = f(ind-2, heights, dp) + abs(heights[ind] - heights[ind-2]);
    return dp[ind] = min(left, right);
}

int frogJump(vector<int> &heights, int n) {

    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}

int main()
{
    vector<int> heights = {10, 20, 30, 10};

    cout << "Heights Array: ";
    for (int x : heights)
    {
        cout << x << " ";
    }
    cout << endl;

    int n = heights.size();

    int ans = frogJump(heights, n);

    cout << "Minimum Energy Required = " << ans << endl;

    return 0;
}

// Sample Input 1:
// 2
// 4
// 10 20 30 10
// 3
// 10 50 10
// Sample Output 1:
// 20
// 0
// Explanation of sample input 1:
// For the first test case,
// The frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost).
// Then a jump from the 2nd stair to the last stair (|10-20| = 10 energy lost).
// So, the total energy lost is 20 which is the minimum. 
// Hence, the answer is 20.

// For the second test case:
// The frog can jump from 1st stair to 3rd stair (|10-10| = 0 energy lost).
// So, the total energy lost is 0 which is the minimum. 
// Hence, the answer is 0.