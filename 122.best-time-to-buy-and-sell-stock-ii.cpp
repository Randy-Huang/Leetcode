/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // in this problem, k is positive infinity
        int n = prices.size();
        int dp[n][2];

        // dp[i][k][0] = dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]) 
        // dp[i][k][1] = dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[1]);
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
                // base case
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                continue;
            }

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

