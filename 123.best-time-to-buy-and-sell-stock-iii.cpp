/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int t = 2;

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(t + 1, vector<int>(2)));

        for (int i = 0; i < n; i++) {
            for (int k = t; k > 0; k--) {
                if (i-1 == -1) {
                    // base case
                    printf("i: %d, k: %d\n", i , k);
                    dp[i][k][0] = 0;
                    dp[i][k][1] = -prices[i];
                    continue;
                }

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }

        return dp[n-1][t][0];
    }
};
// @lc code=end

