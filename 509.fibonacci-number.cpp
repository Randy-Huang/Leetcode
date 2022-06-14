/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        //vector<int> dp(n+1, 0);
        return iterative(n);        
    }

    int recursive(int n, vector<int>& dp) {
        // base case
        if (n <= 1) {
            return n;
        }

        if (dp[n] != 0) {
            return dp[n];
        }

        dp[n] = recursive(n-1, dp) + recursive(n-2, dp);
        return dp[n];
    }

    int iterative(int n) {
        if (n < 2) {
            return n;
        }

        int dp1 = 1;
        int dp2 = 0;
        int dpn = 0;

        for (int i = 2; i <= n; i++) {
            dpn = dp1 + dp2 ;
            dp2 = dp1;
            dp1 = dpn;
        }

        return dpn;
    }
};
// @lc code=end

