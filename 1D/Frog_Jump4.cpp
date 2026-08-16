#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int>& height, int k)
{
    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int mmSteps = INT_MAX;

        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                int jump = dp[i - j]
                         + abs(height[i] - height[i - j]);

                mmSteps = min(mmSteps, jump);
            }
        }

        dp[i] = mmSteps;
    }

    return dp[n - 1];
}

int main()
{
    vector<int> height = {30, 10, 60, 10, 60, 50};

    int n = height.size();
    int k = 2;

    cout << frogJump(n, height, k);

    return 0;
}