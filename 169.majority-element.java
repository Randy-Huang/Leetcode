/*
 * @lc app=leetcode id=169 lang=java
 *
 * [169] Majority Element
 */

// @lc code=start

// Reference: https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/easy/169.majority-element
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        int majority = 0;
        for (int i = 0; i < nums.length; i++) {
           if (majority == nums[i]) {
                count++;
           } else if (count > 0) {
               count--;
           } else {
               count = 1;
               majority = nums[i];
           }
        }

        return majority;
    }
}
// @lc code=end

