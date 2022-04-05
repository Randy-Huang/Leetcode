/*
 * @lc app=leetcode id=283 lang=java
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        for (int slow = 0, fast = 0; fast < nums.length; fast++) {
            // no matter what slow is 0, in the case,
            // if the index of slow is the same as the fast
            // just in-place the same value
            if (nums[fast] != 0) {
                int temp = nums[slow];
                nums[slow] = nums[fast];
                nums[fast] = temp;
                slow++;
            }
        }
    }
}
// @lc code=end

