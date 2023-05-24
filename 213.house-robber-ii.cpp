/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }

        vector<int> memoHead(nums.size(), -1);
        int robHead = dp(nums, 0, n - 2, memoHead);

        vector<int> memoTail(nums.size(), -1);
        int robTail = dp(nums, 1, n - 1, memoTail);

        return max(robHead, robTail);
    }

    int dp(vector<int>& nums, int start, int end, vector<int>& memo) {
        if (start >= nums.size() || start > end) {
            return 0;
        }

        if (memo[start] != -1) {
            return memo[start];
        }

        int rob = nums[start] + dp(nums, start + 2, end, memo);
        int robX = dp(nums, start + 1, end, memo );

        memo[start] = max(rob, robX);

        return memo[start];
    }
};
// @lc code=end

