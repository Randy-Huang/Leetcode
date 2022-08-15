/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n == 0) {
                break;
            }
            
            count = (n & 1) ? count + 1 : count;
            n = n >> 1;
        }

        return count;
    }
};
// @lc code=end

