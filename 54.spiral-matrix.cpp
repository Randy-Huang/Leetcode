/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;

        int top = 0;        // increase row and move from left -> right
        int right = n - 1;  // decrease column and move from top -> bottom
        int bottom = m - 1; // decrease row and move right -> left
        int left = 0;       // increase column and move bottom -> top
        while (res.size() < (m * n)) {
            // top
            if (bottom >= top) {
                for (int j = left; j <= right; j++) {
                    res.push_back(matrix[top][j]);
                }
                top++; // increase top to center
            } 

            // right
            if (right >= left) {
                for (int i = top; i <= bottom; i++) {
                    res.push_back(matrix[i][right]);
                }
                right--; // decrease right to center
            }

            // bottom
            if (bottom >= top) {
                for (int j = right; j >= left; j--) {
                    res.push_back(matrix[bottom][j]);
                }
                bottom--; // decrease bottom to center
            }

            // left
            if (right >= left) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++; // increase left to center
            }
        }

        return res;
    }
};
// @lc code=end

