/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        // // Solution 1: recursive
        // int m = dungeon.size();
        // int n = dungeon[0].size();
        // vector<vector<int>> memo(m, vector<int>(n, INT_MIN));

        // // we start from dp[0][0] to do the recursive
        // // and we take dp[0][0] as our final result 
        // // why we don't tkae dp[m-1][n-1]?
        // // because if we take dp[m-1][n-1] as our final result
        // // we cannot know the previous information from
        // // dp[m-1-1][n-1] and dp[m-1][n-1-1]
        // return dp(dungeon, memo, 0, 0);

        // Solution2 
        return interative(dungeon);
    }

    int interative(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));

        for (int i = (m - 1); i >= 0; i--) {
            for (int j = (n - 1); j >= 0; j--) {
                //printf("i: %d, j: %d, val: %d\n", i, j, dungeon[i][j]); 
                if (i == (m - 1) && j == (n - 1)) {
                    // base case 
                    dp[i][j] = dungeon[i][j] >= 0 ? 1 : -dungeon[i][j] + 1;
                    continue;
                }

                int res1 = (j + 1) > (n - 1) ? INT_MAX : dp[i][j + 1];
                int res2 = (i + 1) > (m - 1) ? INT_MAX : dp[i + 1][j];
                int res = min(
                    res1,
                    res2
                ) - dungeon[i][j];

                dp[i][j] = res <= 0 ? 1 : res;
            }
        }

        return dp[0][0];
    }

    int dp(vector<vector<int>>& dungeon, vector<vector<int>>& memo, int i, int j) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        if (i == m || j == n) {
            return INT_MAX;
        }

        //printf("i: %d, j: %d, val: %d\n", i, j, dungeon[i][j]);
        if (i == (m - 1) && j == (n - 1)) {
            // the knife's health level need to be greater than 1
            // we use -dungeon[i][j] the negative result because
            // what we want to make sure is the minimum health,
            // so it must be positive value
            return dungeon[i][j] >= 0 ? 1 : -dungeon[i][j] + 1;
        }

        if (memo[i][j] != INT_MIN) {
            return memo[i][j];
        }

        int res1 = dp(dungeon, memo, i, j + 1);
        int res2 = dp(dungeon, memo, i + 1, j);
        //printf("res1: i: %d, j: %d, val: %d\n", i,j+1,res1);
        //printf("res2: i: %d, j: %d, val: %d\n", i+1,j,res2);

        // res is negative which means the health is positive
        int res = min(res1, res2) - dungeon[i][j];
        memo[i][j] = res <= 0 ? 1 : res;
        
        //printf("compute: i: %d, j: %d, result: %d\n", i, j, dp[i][j]);
        return memo[i][j];
    }
};
// @lc code=end

