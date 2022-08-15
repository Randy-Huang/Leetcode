/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size();
        int steps = 0;

        // we use "nums size - 1" the last second position
        // as the end condition, and just make sure that 
        // steps once is greater than 0, we can consider
        // this jumps can pass the array
        for (int i = 0; i < last - 1; i++) {
            // old steps need to minus 1 in the new index
            steps = max(steps - 1, nums[i]);

            if (steps == 0) {
                return false;
            }
        }

        // must check steps whether it is equal or greater 0
        // because some array nums may only 1 size like [0] or [n]
        return steps >= 0;
    }
};
// @lc code=end

