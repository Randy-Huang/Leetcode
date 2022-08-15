/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));
        
        for(int i = 0; i < n; i++) {
            // base case for n-1 price when i == 0
            if (i-1 == -1) {
                dp[i][0] = 0;
                dp[i][1] = -prices[i];
                //printf("case1: %d, %d\n", dp[i][0], dp[i][1]);
                continue;
            }

            // base case for n-2 price when i == 1
            if (i-2 == -1) {
                dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);

                //   dp[i][1] 
                // = max(dp[i-1][1], dp[i-1][0] - prices[i]);
                // = max(dp[i-1][1], dp[0][0] - prices[i]);
                // = max(dp[i-1][1], 0 - prices[i]);
                // = max(dp[i-1][1], -prices[i]);
                dp[i][1] = max(dp[i-1][1], -prices[i]);
                //printf("case2: %d, %d\n", dp[i][0], dp[i][1]);
                continue;
            }

            // for dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
            // we use dp[i-2][0] present at i-2th we have no stock
            // which means we've already sell stock at i-2th
            // after selling stock, we need to wiat colddown one day i-1
            // so that we can do the transition dp[i-1][0] to dp[i][1]
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }

        return dp[n-1][0];
    }
};
// @lc code=end

