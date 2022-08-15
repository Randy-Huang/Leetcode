/*
 * @lc app=leetcode id=704 lang=cpp
 *
 * [704] Binary Search
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        return iterative2(nums, target, 0, nums.size() - 1);
    }

    int recursive(vector<int>& nums, int target, int start, int end) {
        if (end >= start) {
            int mid = end + (start - end) / 2;
            
            if (target == nums[mid]) {
                return mid;
            }

            if (target > nums[mid]) {
                return recursive(nums, target, mid + 1, end);
            } 

            return recursive(nums, target, start, mid - 1);
        }

        return -1;
    }

    int iterative(vector<int>& nums, int target, int start, int end) {
        while (end >= start) {
            int mid = end + (start - end) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }

    int iterative2(vector<int>& nums, int target, int start, int end) {
        while (end > start) {
            int mid = (start + end) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        if (nums[start] == target) {
            return start;
        } else if (nums[end] == target) {
            return end;
        } 

        return -1;
    }
};
// @lc code=end

