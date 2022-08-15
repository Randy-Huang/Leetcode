/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> candidate;
        recursive(nums, target, 0, candidate, res);
        return res;
    }

    void recursive(vector<int>& nums, int target, int start, vector<int>& candidate, vector<vector<int>>& res) {
        //printf("target: %d, start: %d\n", target, start);
        if (target < 0) {
            return;
        }

        if (target == 0) {
            res.push_back(candidate);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            int val = nums[i];
            if ((target - val) > -1) {
                candidate.push_back(val);
                recursive(nums, target - val, i, candidate, res);
                candidate.pop_back();  
            }
        }
    }
};
// @lc code=end

