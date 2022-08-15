/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        return iterative(nums);
    }

    bool iterative(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) {
            return false;
        }

        int W = sum / 2;
        int N = nums.size();

        vector<int> dp(W+1, false);
        dp[0] = true;
        
        for (int i = 0; i < N; i++) {
            for (int w = W; w >= 0; w--) {
                //printf("i: %d, w: %d, num: %d, remains: %d\n", i, w, nums[i], (w - nums[i]));

                // We need to iterate w from at the end of an array 
                // to prevent the value of dp[w - nums[i]] we updated before
                // it may cause the wrong result
                if (w - nums[i] >= 0) {
                    dp[w] = dp[w] || dp[w - nums[i]];
                }
            }
        }

        return dp[W];
    }

    bool iterative2Dimen(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum += num;
        }

        // If sum cannot modulo 2, it means this array's elements
        // cannot be partitioned into two subsets when sum is odd
        if (sum % 2 != 0) {
            return false;
        }

        int m = nums.size();
        int n = sum / 2;

        // Divided sum into half to our dp table
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        // dp[...][0] means that is full of sum of nums
        for (int i = 0; i <= m; i++) {
            dp[i][0] = true;
        }
        
        for (int i = 1; i <= m; i++) {
            for (int w = 1; w <= n; w++) {
                //printf("i: %d, w: %d, num: %d, the remains total w: %d\n", i, w, nums[i-1], (w - nums[i-1]));
                if ((w - nums[i-1]) < 0) {
                    // we cannot put any num to the subset
                    dp[i][w] = dp[i-1][w]; 
                } else {
                    dp[i][w] = max(dp[i-1][w], dp[i-1][w - nums[i-1]]);
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

