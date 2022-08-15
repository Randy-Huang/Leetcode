/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4741122.html
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // the core method
        // use "diff & -diff" to divide two numbers from 
        // be not the same bit 

        // be careful, use type 'int' will receive an error message 
        // "runtime error: negation of -2147483648 cannot be represented in type 'int'; cast to an unsigned type to negate this value to itself"
        // reason: https://blog.csdn.net/u012164906/article/details/120092483
        //
        // unsigned int diff = 0;
        // for (auto& num : nums) {
        //     diff ^= num;
        // }

        // the seond method to iterate nums doing XOR
        unsigned int diff = accumulate(nums.begin(), nums.end(), 0, [](int a, int b){ return a ^ b; });

        diff &= -diff;
        vector<int> res(2, 0);
        for (auto& num : nums) {
            if (num & diff) {
                res[0] ^= num; 
            } else {
                res[1] ^= num;
            }
        }

        return res;
    }
};
// @lc code=end

