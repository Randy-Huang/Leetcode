/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1, 0);
        return recursive(n, dp);
    }

    int recursive(int n, vector<int>& dp) {
        if (n < 2) {
            return n;
        }

        if (n == 2) {
            return 1;
        }

        if (dp[n] != 0) {
            return dp[n];
        }

        dp[n] = recursive(n-1, dp) + recursive(n-2, dp) + recursive(n-3, dp);
        return dp[n];
    }

    int iterative(int n, vector<int>& dp) {
        if (n < 2) {
            return n;
        }    

        if (n == 2) {
            return 1;
        }

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};
// @lc code=end

