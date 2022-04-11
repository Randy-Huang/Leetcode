/*
 * @lc app=leetcode id=88 lang=java
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

// Reference: https://leetcode-solution-leetcode-pp.gitbook.io/leetcode-solution/easy/88.merge-sorted-array
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int current = m + n - 1; // from the nums1's tail
        while (current >= 0) {
            if (n == 0) {
                return;
            }

            // all m elements has handled, 
            // just put the remains n elements to nums1
            if (m < 1) {
                nums1[current--] = nums2[--n];
                continue;
            }

            if (nums2[n - 1] > nums1[m - 1]) {
                nums1[current--] = nums2[--n];
            } else {
                nums1[current--] = nums1[--m];
            }
        }
    }
}
// @lc code=end

