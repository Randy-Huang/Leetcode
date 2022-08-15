/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n =matrix.size();

        int res = INT_MAX;
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));

        for (int j = 0; j < matrix.size(); j++) {
            res = min(res, dp(matrix, memo, 0, j));
        }
        return res;
    }

    int dp(vector<vector<int>>& matrix, vector<vector<int>>& memo, int i, int j) {
        int n = matrix.size();

        // base case
        if (i >= n || (j < 0 || j >= n)) {
            return INT_MAX;
        }

        // base case
        if (i == n - 1) {
            return matrix[i][j];
        }

        if (memo[i][j] != INT_MAX) {
            return memo[i][j];
        }

        memo[i][j] = getMin(
            dp(matrix, memo, i + 1, j - 1),
            dp(matrix, memo, i + 1, j),
            dp(matrix, memo, i + 1, j + 1)
        ) + matrix[i][j];
        return memo[i][j];
    }

    int getMin(int a, int b, int c) {
        return min(a, min(b, c));
    }
};
// @lc code=end

