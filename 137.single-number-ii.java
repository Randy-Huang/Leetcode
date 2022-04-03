/*
 * @lc app=leetcode id=137 lang=java
 *
 * [137] Single Number II
 */

// @lc code=start
// Reference: https://xiaotaoguo.com/p/leetcode-137/
// Reference: https://leetcode-cn.com/problems/single-number-ii/comments/
class Solution {
    public int singleNumber(int[] nums) {
        return solution2(nums);
    }

    public int solution2(int[] nums) {
        int one = 0;
        int two = 0;
        
        // x & ~x = 0
        // x & ~0 = x
        // x & ~1 = 0
        for (int i = 0; i < nums.length; i++) {
            one = (one ^ nums[i]) & ~two;
            two = (two ^ nums[i]) & ~one;
        }

        return one;
    }

    public int solution1(int[] nums) {
        int number = 0;

        for (int bit = 0; bit < 32; bit++) {
            int bitCount = 0;
            for (int num : nums) {
                bitCount += ((num >> bit) & 1);
            }

            number |= (bitCount % 3) << bit; 
        }

        return number;
    }
}
// @lc code=end

