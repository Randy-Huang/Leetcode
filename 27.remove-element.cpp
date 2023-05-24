/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int resizePos = 0; // as slow pointer

        for (int i = 0 /* as fast pointer*/; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[resizePos++] = nums[i];
            }
        }

        return resizePos;
    }
};
// @lc code=end

