/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
// Solution 1: Brute force
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = INT_MIN;
//         for (int i = 0; i < nums.size(); i++) {
//             int loopRes = 0;
//             for (int j = i; j < nums.size(); j++) {
//                 loopRes += nums[j];
//                 res = max(res, loopRes);
//             }
//         }

//         return res;
//     }
// };

// Solution 2: Greedy
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int res = INT_MIN;
//         int local = 0;

//         for (int i = 0; i < nums.size(); i++) {
//             local += nums[i];
//             res = max(local, res);

//             if (local < 0) {
//                 local = 0;
//             }
//         }

//         return res;
//     }
// };

// Solution 3: Sliding window
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int left = 0;
//         int right = 0;

//         int windowSum = 0;
//         int maxSum = INT_MIN;

//         while (right < nums.size()) {
//             windowSum += nums[right++];
//             maxSum = max(windowSum, maxSum);

//             while (windowSum < 0) {
//                 windowSum -= nums[left++];
//             }
//         }

//         return maxSum;
//     }
// };

// Solution 4: DP
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         if (nums.size() == 0) {
//             return 0;
//         }

//         vector<int> dp(nums.size(), 0);
//         dp[0] = nums[0];

//         int res = dp[0];

//         for (int i = 1; i < nums.size(); i++) {
//             dp[i] = max((dp[i-1] + nums[i]), nums[i]);
//             res = max(dp[i], res);
//         }

//         return res;
//     }
// };

// Solution 5: Divide and conquer
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        return divideAndConquerHelper(nums, 0, nums.size() - 1);
    }

    int divideAndConquerHelper(vector<int>&nums, int left, int right) {
        if (left >= right) {
            // if left == right, which is only one element in the specified range
            // and it is the sum itself
            return nums[left];
        }

        int mid = left + (right - left) / 2;

        // divide part
        // 1. the sum of the left of nums
        int subLeftMaxSum = divideAndConquerHelper(nums, left, mid);

        // 2. the sum of the right of nums
        int subRightMaxSum = divideAndConquerHelper(nums, mid + 1, right);

        // We not only calculate both sums of left and right 
        // but also calculate the cross sum may have consecutive elements to add them up to the sum
        // bewtween subLeftMaxSum and subRightMaxSum
        // for example, [1,-3,4,-2,1,6,-2]，
        // if we just let subLeftMaxSum and subRightMaxSum add together
        // the max sum in the left part of an array is 4
        // the max sum in the right part of an array is 7, then we have 4 + 7 = 11
        // but the added result isn't a consecutive result 
        // it don't satisfy the condition of the question that need a consecutive result in Subarray

        // we know the maxmium subarray is [4,-2,1,6] and its sum is 9
        // therefore, we need to calculate at mid, 
        // one direction is from mid as right point to the left point for the left part
        // one direction is from mid + 1 as left point to the right point for the right part
        // and then we add them up as max sum for the crossing left and right part of an array 
        // and also promise the cross sum is consecutive.
        
        int maxSum = INT_MIN;
        int crossSum = 0;

        // corss sum of the left part
        for (int i = mid; i >= left; i--) {
            crossSum += nums[i];
            maxSum = max(maxSum, crossSum);
        }

        crossSum = maxSum; 
        for (int i = mid + 1; i <= right; i++) {
            crossSum += nums[i];
            maxSum = max(maxSum, crossSum);
        }

        return max({maxSum, subLeftMaxSum, subRightMaxSum});
        
        // The total TC is O(nlogn), n is the length of an array
        // we iterate an sub array which is TC is O(n)
        // and every array is divided from two parts, and TC is O(logn)
        // so the total TC come to O(nlogn)
    }
};
// @lc code=end

