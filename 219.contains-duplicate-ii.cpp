/*
 * @lc app=leetcode id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); i++) {
            if (!map.count(nums[i])) {
                map.insert({nums[i], i});
                continue;
            } 
            
            int diff = abs(map[nums[i]] - i);
            if (diff <= k) {
                return true;
            } else { // update index if k is smaller than diff
                map[nums[i]] = i;
            }
        }

        return false;
    }
};
// @lc code=end

