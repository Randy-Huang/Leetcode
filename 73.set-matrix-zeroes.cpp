/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

// Solution 2: Effecient way to use the first row and column as indicator
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool rowZero = false;
        bool colZero = false;

        // Rather than using additional variables to keep track of rows and columns 
        // to be reset, we use the matrix itself as the indicators.
        //
        // The idea is that we can use the first cell of every row and column as a flag. 
        // This flag would determine whether a row or column has been set to zero. 
        // This means for every cell instead of going to M+N cells and setting it to zero 
        // we just set the flag in two cells

        // Step 1: 
        // Before we use the first cell of every row and column as a flag
        // we use two flags to record whether the first column and row have any 0 elements
        // and then both flags will be used in step 4
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                rowZero = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                colZero = true;
                break;
            }
        }

        // Step 2:
        // Use the first cell of every row and column as a flag.
        // If an element is zero, we set the first element of the corresponding row and column to 0
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 3:
        // Iterate over the array once again and use the first row and first column 
        // as indicators to update the elements.
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4:
        // See if the first row and column need to be set to zero as well
        if (rowZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }        
        }

        if (colZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

// Solution 1: use extra memory space (m+n) approach
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         if (matrix.empty() || matrix[0].empty()) {
//             return;
//         }

//         // m row * n column
//         int m = matrix.size();
//         int n = matrix[0].size();

//         vector<int> row(m, 1);
//         vector<int> col(n, 1);

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == 0) {
//                     row[i] = 0;
//                     col[j] = 0;
//                 }
//             }
//         }


//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (row[i] == 0 || col[j] == 0) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }
//     }
// };
// @lc code=end

