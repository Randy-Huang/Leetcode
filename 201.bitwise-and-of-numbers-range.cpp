/*
 * @lc app=leetcode id=201 lang=cpp
 *
 * [201] Bitwise AND of Numbers Range
 */

// @lc code=start
class Solution {
public:
    // solution 1:
    int rangeBitwiseAnd(int left, int right) {
        unsigned int mask = INT_MAX;
        while ((left & mask) != (right & mask)) {
            mask <<= 1;
        }

        return mask & right;
    }

    // solution 2
    // int rangeBitwiseAnd(int left, int right) {
    //     int count = 0;
    //     while (right != left) {
    //         right >>= 1;
    //         left >>= 1;
    //         count++;
    //     }

    //     return left << count;
    // }
};
// @lc code=end

