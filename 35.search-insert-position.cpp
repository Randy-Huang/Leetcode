/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int first = 0;
        int last = n;

        while (first < last) {
            int mid = first + (last - first) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid;
            }
        }

        return first;
    }
};
// @lc code=end

