/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // for recursive
        // vector<int> memo(amount + 1, INT_MIN);
        // return recursiveDp(coins, memo, amount);

        // for iterative
        return iterative(coins, amount);
    }

    int iterative(vector<int>& coins, int amount) {

        // We use  amount + 1 instead of INT_MAX amount
        // to prevent dp[i - coin] leading overflow
        int overAmount = amount + 1;
        vector<int> dp(amount + 1, overAmount);
        dp[0] = 0;


        // dp[i], when i is amount of money, it need
        // coins dp[i]
        for (int i = 0; i < dp.size(); i++) {
            for (auto coin : coins) {
                if (i - coin < 0) {
                    continue;
                }

                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
            //printf("i: %d, amount: %d\n", i, dp[amount]);
        }   
        
        return dp[amount] == overAmount ? -1 : dp[amount];
    }

    /*
     * amount: the remain amount of money.
     * coins: representing coins of different denominations 
     * 
     * return: the mininum amount of coins for amount of money 
     * */
    int recursiveDp(vector<int>& coins, vector<int>& memo, int amount) {
        // the definition of base cases
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return -1;
        }

        if (memo[amount] != INT_MIN) {
            return memo[amount];
        }

        int res = INT_MAX;
        for (auto coin : coins) {
            int subCoinAmount = recursiveDp(coins, memo, amount - coin);
            if (subCoinAmount == -1) {
                continue;
            }

            res = min(res, subCoinAmount + 1);
        }

        memo[amount] = res == INT_MAX ? -1 : res;
        return memo[amount];
    }
};
// @lc code=end

