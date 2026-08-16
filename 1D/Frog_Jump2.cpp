// Memoization Method

#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     vector<int> heights = {30, 10, 60, 10, 60, 50};
//     int n = heights.size();
//     vector<int> dp(n, 0);

//     cout << "Heights Array: ";
//     for (int x : heights)
//     {
//         cout << x << " ";
//     }
//     cout << endl;

//     dp[0] = 0;
//     for(int i=1; i<n; i++) {
//         int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
//         int ss = INT_MAX;
//         if(i > 1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);

//         dp[i] = min(fs, ss);
//     }
//     cout << dp[n-1];
//     return 0;
// }

// Optimal Space

int main()
{
    vector<int> heights = {30, 10, 60, 10, 60, 50};
    int n = heights.size();

    cout << "Heights Array: ";
    for (int x : heights)
    {
        cout << x << " ";
    }
    cout << endl;

    int prev = 0;
    int prev2 = 0;
    for(int i=1; i<n; i++) {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);

        int curri = min(fs, ss);
        prev2 = prev;
        prev=  curri;
    }
    cout << prev;
    return 0;
}