/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) {
            return 0;
        }

        if (k > (n / 2)) {
            return maxProfitUnlimitedK(prices);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2)));
        // base case for k
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = -prices[i];
        }

        for (int i = 0; i < n; i++) {
            for (int t = k; t > 0; t--) {
                if (i-1 == -1) {
                    // base case for dp[i-1][][] case
                    dp[i][t][0] = 0;
                    dp[i][t][1] = -prices[i];
                    continue;
                }

                dp[i][t][0] = max(dp[i-1][t][0], dp[i-1][t][1] + prices[i]);
                dp[i][t][1] = max(dp[i-1][t][1], dp[i-1][t-1][0] - prices[i]);
            }
        }

        return dp[n-1][k][0];
    }

    int maxProfitUnlimitedK(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> dp(n, vector<int>(2));

        for (int i = 0; i < n; i++) {
             if (i-1 == -1) {
                // base case for dp[i-1][][] case
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

