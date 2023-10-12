/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
// Solution 1: Traversing start from the bottom-left corner elemnts to opposite
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = m -1;
        int j = 0;

        while (i >= 0 && j < n) {
            //printf("n: %d, value: %d\n", n, matrix[i][j]);
            if (matrix[i][j] == target) {
                return true;
            } else if (matrix[i][j] > target) {
                i--;
            } else {
                j++;
            }
        }

        return false;
    }
};
// @lc code=end

