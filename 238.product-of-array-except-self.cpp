/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Notice:
        // 1. if we have one zero, only the position which is zero has pdoduct and others are 0
        // 2. if we have two more zero, then the product array are all zero

        vector<int> products(nums.size(), 0);

        int maxProduct = 1;
        int zeroPos = -1;
        int numOfZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                numOfZero++;
                zeroPos = i;
                continue;
            }

            maxProduct *= nums[i];
        }

        if (numOfZero > 1) {
            return products;
        }

        if (numOfZero == 1) {
            products[zeroPos] = maxProduct;
            return products;
        }

        for (int i = 0; i < nums.size(); i++) {
            products[i] = maxProduct / nums[i];
        }

        return products;
    }
};
// @lc code=end

