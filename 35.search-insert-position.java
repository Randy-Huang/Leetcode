/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        return recursive(nums, left, right, target);
    }

    // Recursive implementation of Binary Search
    public int recursive(int nums[], int left, int right, int target) {
        if (right >= left) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            return recursive(nums, left, right, target);
        }

        return left;
    }

    // Iterative implementation of Binary Search
    public int iterative(int[] nums, int left, int right, int target) {
        while (right >= left) {
            int mid = (right + left) / 2; // mid = left + (right - left) / 2
            if (nums[mid] == target) {
                return mid;
            }

            // target num is grater, ignore left half
            if (nums[mid] < target) {
                left = mid + 1;
            } else { // nums[mid] > target, ignore right half if target is smaller
                right = mid - 1;
            }
        } 

        return left;
    }
}
// @lc code=end

