/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return iterative(amount, coins);
    } 

    int iterative(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<int> dp(amount+1, 0);

        // base case
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            // we iterate w from the beginning because dp[w] 
            // needs the last state dp[w] + dp[w - coins[i]]
            // and we also have an infinite number of each kind of coin
            // to use 
            for (int w = 1; w <= amount; w++) {
                if (w - coins[i] >= 0) {
                    dp[w] = dp[w] + dp[w - coins[i]];
                }
            }
        }

        return dp[amount];
    }

    int iterative2dDimen(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        // base case
        for (int i = 0; i <= n; i++) {
            // if the amount is 0, there is only one way to match 0
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= amount; w++) {
                // printf("i: %d, w: %d, remains: %d\n ", i, w, w - coins[i-1]);
                if (w - coins[i-1] < 0) {
                    dp[i][w] = dp[i-1][w];
                } else {
                    // because we have an infinite number of each kind of coin
                    // so we use dp[i][w - coins[i-1]] not dp[i-1][w - coins[i-1]]
                    // dp[i-1][...] means we've chosen a coin that only can use once
                    dp[i][w] = dp[i][w - coins[i-1]] + dp[i-1][w];
                }
            }
        }

        return dp[n][amount];
    }
};
// @lc code=end

