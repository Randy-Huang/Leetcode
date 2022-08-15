/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        
        int top = 0;        // increase to center from left to right
        int right = n - 1;  // decrease to center from top to bottom
        int bottom = n - 1; // decrease to center from right to left
        int left = 0;       // increase to center from bottom to top

        int num = 1;
        while (num <= (n*n)) {
            if (bottom >= top) {
                for (int j = left; j <= right; j++) {
                    matrix[top][j] = num++;
                }
                top++;
            }

            if (right >= left) {
                for (int i = top; i <= bottom; i++) {
                    matrix[i][right] = num++;
                }
                right--;
            }

            if (bottom >= top) {
                for (int j = right; j >= left; j--) {
                    matrix[bottom][j] = num++;
                }
                bottom--;
            }

            if (right >= left) {
                for (int i = bottom; i >= top; i--) {
                    matrix[i][left] = num++;
                }
                left++;
            }
        }

        return matrix;
    }
};
// @lc code=end

