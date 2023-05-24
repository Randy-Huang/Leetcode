/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

// Reference: https://www.cnblogs.com/grandyang/p/4028713.html

// Solution 2: Don't need extra space
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int n = nums.size();

        int maxP = res;
        int minP = res;

        for (int i = 1; i < n; i++) {
            int maxL = maxP; // means maxP[i-1]
            int minL = minP; // means minP[i-1]

            maxP = max(max(maxL * nums[i], minL * nums[i]), nums[i]);
            minP = min(min(maxL * nums[i], minL * nums[i]), nums[i]);
            res = max(maxP, res);
        }

        return res;
    }
};

// Solution 1: use two extra space for dp. space complexity: O(N)
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         int res = nums[0];
//         int n = nums.size();

//         vector<int> maxP(n, 0);
//         vector<int> minP(n, 0);

//         maxP[0] = res;
//         minP[0] = res;

//         for (int i = 1; i < n; i++) {
//             maxP[i] = max(max(maxP[i-1] * nums[i], minP[i-1] * nums[i]), nums[i]);
//             minP[i] = min(min(maxP[i-1] * nums[i], minP[i-1] * nums[i]), nums[i]);  
            
//             // Notice maxP and minP have not global max or min value in arrays
//             // so we need to use res to compare them
//             res = max(maxP[i], res);
//         }

//         return res;
//     }
// };
// @lc code=end

