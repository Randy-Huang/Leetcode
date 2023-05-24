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

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int lower = matrix[0][0];
        int upper = matrix.back().back();

        while (lower < upper) {
            int middle = (lower + upper) >> 1;
            //printf("middle: %d\n", middle);
            int lessThan = 0;

            // num[i][j] < nums[i+1][j] && nums[i][j-1] < nums[i][j]
            // and j-1 is a the largest element in a subarray
            for (int i = 0, j = n - 1; i < n; i++) {
                while (j >= 0 && matrix[i][j] > middle) {
                    j--;
                }
                lessThan += j + 1;
            }

            if (lessThan < k) {
                lower = middle + 1;
            } else {
                upper = middle;
            }
        }

        return lower;
    }
};
// @lc code=end

