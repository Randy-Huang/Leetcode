/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m = obstacleGrid.size();
//         int n = obstacleGrid[0].size();

//         vector<vector<int>> dp(m, vector<int>(n, 0));
//         for (int i = 0; i < m; i++) {
//             if (obstacleGrid[i][0] == 1) {
//                 break;
//             }

//             dp[i][0] = 1;
//         }

//         for (int j = 0; j < n; j++) {
//             if (obstacleGrid[0][j] == 1) {
//                 break;
//             }

//             dp[0][j] = 1;
//         }


//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 if (obstacleGrid[i][j] == 1) {
//                     continue;
//                 }

//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];
//             }
//         }


//         return dp[m-1][n-1];
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            dp[i] = 1;
        }

        for (int i = 1; i < m; i++) {
            // for obstacleGrid[i][0] and obstacleGrid[j][0]
            // if there is one cell being 1, others behind 
            // the cell always should be 0
            if (dp[0] == 0 || obstacleGrid[i][0] == 1) {
                dp[0] = 0; 
            }

            for (int j = 1; j < n; j ++) {
                if (obstacleGrid[i][j] != 1) {
                    dp[j] = dp[j-1] + dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }

        return dp.back();
    }
};
// @lc code=end

