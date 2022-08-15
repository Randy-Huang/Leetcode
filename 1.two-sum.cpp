/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map = unordered_map<int, int>(nums.size());
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i])) {
                res.push_back(map[nums[i]]);
                res.push_back(i);
                break;
            }

            int key = target - nums[i];
            map[key] = i;
        }

        return res;
    }
};
// @lc code=end

