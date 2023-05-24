/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size() + 2, -1);
        return dp(nums, 0, memo);
    }

    int dp(vector<int>& nums, int start, vector<int>& memo) {
        if (start >= nums.size()) {
            return 0;
        }

        if (memo[start] != -1) {
            return memo[start];
        }

        // we have two selection: rob or not rob
        // 1. rob: nums[start] + dp(nums, start + 2, memo)
        // 2. Don't rob: dp(nums, start + 1, memo)
        int rob = nums[start] + dp(nums, start + 2, memo);
        int robX = dp(nums, start + 1, memo);
        memo[start] = max(rob, robX);

        return memo[start];
    }
};
// @lc code=end

