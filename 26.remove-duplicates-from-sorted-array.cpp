/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;

        int current = 0;
        for (int next = 0; next < nums.size(); next++) {
            if (current != next) {
                if (nums[current] == nums[next]) {
                    continue;
                }
                
                nums[++current] = nums[next];
                k++;
            }
        }

        return k;
    }
};
// @lc code=end

