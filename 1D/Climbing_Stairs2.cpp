#include <iostream>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return 1;

    int prev2 = 1; // dp[0]
    int prev1 = 1; // dp[1]

    for (int i = 2; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n;

    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Number of ways = " << climbStairs(n) << endl;

    return 0;
}