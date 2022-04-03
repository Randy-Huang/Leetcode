/*
 * @lc app=leetcode id=260 lang=java
 *
 * [260] Single Number III
 */

// @lc code=start
// Reference: https://leetcode.com/problems/single-number-iii/discuss/68922/A-summary-of-Java-solutions
// Reference: https://oceanprince.wordpress.com/2019/04/15/leetcode260-single-number-iii/
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] results = new int[2];

        int twoXor = 0;
        for (int num : nums) {
            twoXor ^= num;
        }

        // There's at least a bit different between two numbers
        // We just find the bit to be a mask 
        // to divide them into two numbers 
        int mask = twoXor & -twoXor;
        for (int num : nums) {
            if ((mask & num) == 0 ) {
                results[0] ^= num;
            } else {
                results[1] ^= num;
            }
        }

        return results;
    }
}
// @lc code=end

