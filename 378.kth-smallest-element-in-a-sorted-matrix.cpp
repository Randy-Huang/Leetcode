// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem378.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=378 lang=cpp
 *
 * [378] Kth Smallest Element in a Sorted Matrix
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/5727892.html
// Reference: https://home.gamer.com.tw/artwork.php?sn=5307821

// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int lower = matrix[0][0];
//         int upper = matrix.back().back();

//         while (lower < upper) {
//             int middle = (lower + upper) >> 1;
//             //printf("middle: %d\n", middle);
//             int lessThan = 0;

//             // num[i][j] < nums[i+1][j] && nums[i][j-1] < nums[i][j]
//             // and j-1 is a the largest element in a subarray
//             for (int i = 0, j = n - 1; i < n; i++) {
//                 while (j >= 0 && matrix[i][j] > middle) {
//                     j--;
//                 }
//                 lessThan += j + 1;
//             }

//             if (lessThan < k) {
//                 lower = middle + 1;
//             } else {
//                 upper = middle;
//             }
//         }

//         return lower;
//     }
// };

// 2023.07.19
// Solution Use to binary search
// one is find the middle value and then we count the value 
// how many numbers are less than the current middle value
// in the first BS, use lower_bound() to find the value which is >= k
// in the second BS, use upper_bound() to find out how many numbers in a column
// are smaller than middle number, note that we cannot use lower_bound
// because we don't want to count the same value.
// we must use upper_bound() because
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         int n = matrix.size();
//         int firstVal = matrix[0][0];
//         int lastVal = matrix[n-1][n-1];

//         // lower_bound()
//         while (firstVal < lastVal) {
//             int midVal= firstVal + (lastVal - firstVal) / 2;
//             int iLessThan = 0;

//             for (int i = 0; i < n; i++) {
//                 iLessThan += binarySearch(matrix[i], midVal);
//             }
//             //printf("start:%d, end: %d, midVal: %d, iLessThan: %d\n", firstVal, lastVal, midVal, iLessThan);
//             if (iLessThan < k) { // need to find the part of those greater values
//                 firstVal = midVal + 1;
//             } else {
//                 lastVal = midVal;
//             }
//         }

//         return firstVal;
//     }

//     // upper_bound
//     int binarySearch(vector<int>& column, int value) {
//         int first = 0;
//         int last = column.size();
        
//         while (first < last) {
//             int mid = first + (last - first) / 2;
//             if (column[mid] <= value) {
//                 first = mid + 1;
//             } else {
//                 last = mid;
//             }
//         }
//         //printf("return: %d\n", first);
//         return first;
//     }
// };

// 2023.07.21
// Solution 2: binary search and reduce range
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int first = matrix[0][0];
        int last = matrix.back().back();

        while (first < last) {
            int mid = first + (last - first) / 2;
            int count = compareLessThanOrEqual(matrix, mid);
            if (count < k) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }

        return first;
    }

    int compareLessThanOrEqual(vector<vector<int>>& matrix, int value) {
        int n = matrix.size();

        // we start from matrix[n-1][0] that is in the left-bottom side
        // and do compare its right element and above.
        int i = n - 1; 
        int j = 0;

        int count = 0;
        while (i >= 0 && j < n) {
            //  1  5  9
            // 10 11 13
            // 12 13 15
            if (matrix[i][j] <= value) {
                j++;
                // if we find a element that is less than or equal to
                // middle value, then we can promise all elements
                // from current i-th to 0, which means current matrix[i-1][j],
                // matrix[i-2][j],... ,matrix[0][j] are less than or equal to
                // matrix[i][j]
                count += (i + 1);
            } else {
                // if we find a element but greater than value
                // then we just go up one step which means i-1
                i--;
            }
        }

        return count;
    }
};
// @lc code=end

