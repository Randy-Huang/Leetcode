/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();

        // exchange elements by mirror change along with 
        // diagonal line matrix[0][0] - matrix[n-1][n-1]
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // reverse elements every row
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (n / 2); j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};
// @lc code=end

