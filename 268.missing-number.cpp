/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4756677.html
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        return bitwise(nums);
    }

    // Solution 1: 
    int bitwise(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            // general speaking, we start from 0
            // and if there is no missing number
            // the result will be 0 because every 
            // item i xor value will be 0 eventually.
            // but in this problem
            // we will get the non-zero result for the missing number
            res ^= (nums[i] ^ (i + 1)); // we don't need to care the case "i = 0"
        }
        return res;
    }

    // Solution 2: The sum of arithmetic progression
    int math(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        // [NOTICE]
        // sum = (n * a0) + d * ((n * (n-1)) / 2)
        // we always start from 0
        // so for the (n * a0), it will be 0 and d = 1
        // and then we have the reslut below
        return ((n * (n + 1) >> 1) - sum);
    }
};
// @lc code=end

