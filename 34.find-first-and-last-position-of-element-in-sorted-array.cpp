/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {left_bound(nums, target), right_bound(nums, target)};
    }

    int left_bound(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) {
            int mid = ((lo + hi) >> 1);
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] == target) {
                hi = mid - 1;
            }
        }

        if (lo >= nums.size() || nums[lo] != target) {
            return -1;
        }

        return lo;
    }

    int right_bound(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo <= hi) { 
            int mid = (lo + hi) >> 1;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else if (nums[mid] == target) {
                lo = mid + 1;
            }
        }
        
        if (hi < 0 || nums[hi] != target) {
            return -1;
        }

        return hi;
    }
};
// @lc code=end

