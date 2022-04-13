/*
 * @lc app=leetcode id=26 lang=java
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int count = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[count] != nums[i]) {
                // in-place to the next element
                nums[++count] = nums[i];
            }
        }

        // if count == 0, which means this array is empty
        return (nums.length != 0) ? ++count : 0;
    }
}
// @lc code=end

