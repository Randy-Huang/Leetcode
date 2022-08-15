/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        return prefixSum(nums, k);
    }

    int prefixSum(vector<int>& nums, int k) {
        vector<int> prefix_sum(nums.size() + 1, 0);

        for (int i = 1; i <= nums.size(); i++) {
            prefix_sum[i] = prefix_sum[i-1] + nums[i-1];
        }

        int res = 0;
        unordered_map<int, int> record;
        for (int i = 0; i < prefix_sum.size(); i++) {
            // we want to find the equation:
            // prefix_sum[] - k = target
            // it means we just find out prefix_sum[] - k, 
            // so that we can find the sub arrasy which is sum is k
            // and we can use map to record how many times 
            // prefix_sum[] - k occurs in the prefix sum
            //
            //      array:    [3, 5,  2, -2,  4,  1], k = 5
            // prefix sum: [0, 3, 8, 10,  8, 12, 13] 
            int key = prefix_sum[i] - k;
            //printf("prefix: %d, key: %d, times: %d\n", prefix_sum[i],key, record[key]);
            if (record.count(key)) {
                res += record[key];
            }
            int newKey = prefix_sum[i];
            record[newKey] = record.count(newKey) ? record[newKey] + 1 : 1;
        }
        
        return res;
    }

    // wrong solution using two pointers
    // because the sub sequence of an array might cotain duplicated elements
    // for example
    // [1, 2, 3, 1], k = 6, and then the result is 2
    // in this case , the two results are [1, 2, 3] and [2, 3, 1]
    // so we just use prefix sum
    int twoPointers(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        for (int left = 0, right = 0; right < nums.size();) {
            sum += nums[right];
            if (sum == k ) {
                res++;
                sum = 0;
                left = right;
            } 

            right++;
        }

        return res;
    }
};
// @lc code=end

