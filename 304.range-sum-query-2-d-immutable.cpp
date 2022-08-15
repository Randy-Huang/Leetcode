/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start
class NumMatrix {
public:
    // we use 2D dimension preSum to record every prefix sum 
    // from (0,0) to (i-1, j-1) of an array
    vector<vector<int>> preSum;

    NumMatrix(vector<vector<int>>& matrix) {
        preSum = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                preSum[i+1][j+1] = preSum[i][j+1] + preSum[i+1][j] + matrix[i][j] - preSum[i][j];
            }
        }
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        return (preSum[x2+1][y2+1] - preSum[x2+1][y1] - preSum[x1][y2+1] + preSum[x1][y1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

