/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4325648.html
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] < nums[end]) { 
                // the right side of the mid in the array is in ascending order
                if (nums[mid] < target && nums[end] >= target) {
                    start = mid + 1; 
                } else {
                    end = mid - 1;
                }
            } else { // nums[mid] >= nums[end]
                // the left side of the mid in the array is in asceding order
                if (nums[mid] > target && nums[start] <= target) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }

        return -1;
    }
};
// @lc code=end

