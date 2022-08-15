/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // For recursive
        //
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return dp(grid, memo, m - 1, n - 1);

        // For iterative
       return iterative(grid);
    }

    int iterative(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // base case
        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }

    int dp(vector<vector<int>>& grid, vector<vector<int>>& memo, int m, int n) {
        // base case
        if (m == 0 && n == 0) {
            return grid[0][0];
        }

        if (m < 0 || n < 0) {
            // use max value in case the most value
            // will not be selected to our result
            return INT_MAX; 
        }

        if (memo[m][n] != -1) {
            return memo[m][n];
        }

        memo[m][n] = min(dp(grid, memo, m -1, n), dp(grid, memo, m, n - 1)) + grid[m][n];
        return memo[m][n];
    }
};
// @lc code=end

