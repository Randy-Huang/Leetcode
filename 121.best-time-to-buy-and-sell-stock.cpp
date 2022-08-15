/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Here we only have 2 states need to take care
        // one is prices per each day, 
        // two is operations: sell, buy, and reset
        vector<vector<int>> dp(n, vector<int>(2));

        // General transition function for all problems like this type:
        // dp[i][k][0] = max(dp[i-1][k][0]), dp[i-1][k][1]) + prices[i]);
        // dp[i][k][1] = max(dp[i-1][k][1]), dp[i-1][k-1][0]) - prices[i]);
        //
        // Here, our k is only 1, 
        // dp[i][1][1] = max(dp[i-1][1][1]), dp[i-1][0][0]) - prices[i]);
        // where dp[i-1][0][0] = 0 we have no chage to but sotck when k = 0
        // so we can reduce the second item
        // dp[i][1][1] = max(dp[i-1][1][1]), -prices[i])
        for (int i = 0; i < n; i++) {
            if (i - 1 == -1) {
                // base case
                // dp[-1][0] = 0: 
                // price is start from 0, 
                // so i = -1 that is impossible to have profit
                // 
                // dp[-1][1] = -infinity
                // we cannot buy stock from i = -1
                dp[0][0] = 0;
                dp[0][1] = -prices[0];
                continue;
            }

            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

