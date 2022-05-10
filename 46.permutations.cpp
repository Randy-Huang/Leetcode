/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start

// Reference: https://leetcode.com/problems/permutations/discuss/1961596/C%2B%2B-oror-Easy-to-Understand-with-Diagram-oror-0-ms-oror-Backtracking
// Reference: https://leetcode.com/problems/permutations/discuss/1796331/Backtracking-oror-faster-than-100.00-of-C%2B%2B-online-submissions
class Solution {
public:
    // Solution 1
    vector<vector<int>> permute(vector<int>& nums) {
        // record the path we've visited
        vector<vector<int>> res;

        // set the start of a path, which means we fixed a path we visited before start point
        int start = 0;

        backtrack(res, nums, start);

        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, int start) {
        // the condition to stop backtracking
        if (nums.size() == start) {
            res.push_back(nums);
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            backtrack(res, nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }

    // Solution 2
    // vector<vector<int>> res;

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<int> track;
    //     backtrack(nums, track);
    //     return res;
    // }

    // void backtrack(vector<int> nums, vector<int> track) {
    //     if (track.size() == nums.size()) {
    //         res.push_back(track);
    //         return;
    //     }

    //     for (int i = 0; i < nums.size(); i++) {
    //         // We don't need to handle the value where is in the track
    //         // because it is fixed in the order
    //         if (find(track.begin(), track.end(), nums[i]) == track.end()) {
    //             track.push_back(nums[i]);
    //             backtrack(nums, track);
    //             track.pop_back();
    //         }
    //     }
    // }
};
// @lc code=end

