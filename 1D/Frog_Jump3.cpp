// K Jump 

#include <bits/stdc++.h>
using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp, int k)
{
    if(ind == 0)
        return 0;

    if(dp[ind] != -1)
        return dp[ind];

    int mmSteps = INT_MAX;

    for(int j = 1; j <= k; j++)
    {
        if(ind - j >= 0)
        {
            int jump = solve(ind - j, height, dp, k)
                     + abs(height[ind] - height[ind - j]);

            mmSteps = min(mmSteps, jump);
        }
    }

    return dp[ind] = mmSteps;
}

int frogJump(int n, vector<int>& height, int k)
{
    vector<int> dp(n, -1);

    return solve(n - 1, height, dp, k);
}

int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};

    int n = height.size();
    int k = 2;

    cout << frogJump(n, height, k);

    return 0;
}