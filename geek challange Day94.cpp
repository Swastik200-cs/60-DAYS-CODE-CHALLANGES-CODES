#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = max(n,
                    solve(n / 2, dp) +
                    solve(n / 3, dp) +
                    solve(n / 4, dp));

        return dp[n];
    }
    int maxSum(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;
    Solution obj;
    cout << "Maximum Sum = " << obj.maxSum(n) << endl;
    return 0;
}