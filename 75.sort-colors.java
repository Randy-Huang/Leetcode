/*
 * @lc app=leetcode id=75 lang=java
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
    public void sortColors(int[] nums) {
        int head = 0;
        int tail = nums.length - 1;

        // we cannot promise nums[0] is 0, so we need to iterate
        // the array from index 0 and end in tail
        for (int i = 0; i <= tail; i++) {
            if (nums[i] == 0) {
                swap(nums, head++, i);
            } else if (nums[i] == 2) {
                // we're not sure that nums[i] value 
                // after swapping between right and i
                // so we need to fixed i in the same index 
                // until next time.
                //
                // this uncertain case will not happen in left flag
                // because index start to come from left side
                // and already check it.
                swap(nums, tail--, i--);
            }
        }
    }

    public void swap(int[] nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
}
// @lc code=end

