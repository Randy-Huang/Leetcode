/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int first = 0; 
        int last = m * n;

        while (first < last) {
            int mid = first + (last - first) / 2;
            int val = getValue(matrix, mid, n);
            if (val == target) {
                return true;
            } else if (val < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }

        return false;
    }

    
    int getValue(vector<vector<int>>& matrix, int idx, int n) {
        int im = idx / n;
        int in = idx % n; 
        return matrix[im][in];
    }
};
// @lc code=end

