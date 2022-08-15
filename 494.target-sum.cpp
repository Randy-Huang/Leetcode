/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        // Solution 1: Backtracking
        // int result = 0;
        // backtracking(nums, result, target, 0);
        // return result;

        // Solution 2: Backtracking + memorization
        // int size = nums.size();
        // unordered_map<string, int> umap(size);
        // return backtracking(nums, umap, target, 0);

        // Solution 3: DP knapsack problem
        // sum and target are always be odd ore even in the same time
        // otherwise it must be 0
        // and this problem give us constraints
        // that most big sum is 1000 and target is 1000
        // so target must not be greater than sum
        // int sum = accumulate(nums.begin(), nums.end(), 0);
        // if (sum < abs(target) || ((target + sum) % 2 == 1)) {
        //     return 0;
        // }
        // return subset(nums, (target + sum) / 2);

        // Solution 4: DP
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < abs(target) || ((target + sum) % 2 == 1)) {
            return 0;
        }
        return subset1Demin(nums, (target + sum) / 2);
    }

    // We can transform this problem into knapsack problem
    // we consider an equation by divided nums into 2 subsets
    // sum(A) - sum(B) = target, which sum(A) means '+' and sum(b) means '-'
    // sum(A) = target + sum(B) 
    // 2 * sum(A) = target + sum(A) + sum(B) = target + sum(nums)
    // sum(A) = (target + sum(nums)) / 2
    //
    // This problem can be transformed into
    // "How many subset are there and they're sum equal to "(target + sum(nums)) / 2"?
    int subset(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        // Definition: dp[i][j] = x
        // There is x ways that can be full of weights in knapsack
        // when weights is j by i items

        // base case
        // when weight is 0 
        // we have only way that just don't put item into knapsack
        dp[0][0] = 1; 

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (j - nums[i-1] < 0) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j - nums[i-1]] + dp[i-1][j];
                }
            }
        }

        return dp[n][sum];
    }

    int subset1Demin(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<int> dp(sum+1, 0);
        dp[0] = 1; 

        for (int i = 1; i <= n; i++) {
            for (int j = sum; j >= 0; j--) {
                if (j - nums[i-1] >= 0) {
                   dp[j] = dp[j - nums[i-1]] + dp[j];
                }
            }
        }

        return dp[sum];
    }

    // enhance backtracking solution with memorization
    int backtracking(vector<int>& nums, unordered_map<string, int >& umap, int target, int i) {
        // base case
        if (i == nums.size()) {
            return (target == 0) ? 1 /* find one possible expression */ : 0;
        }    

        string s = to_string(i) + ',' + to_string(target);
        if (umap.count(s)) {
            return umap[s];
        }

        // do selection for operation '-'    
        int res1 = backtracking(nums, umap, target + nums[i], i+1);

        // do selection for operation '+'
        int res2 = backtracking(nums, umap, target - nums[i], i+1);
        
        umap[s] = res1 + res2;
        return umap[s];
    }

    // O(N^2) solution
    void backtracking(vector<int>& nums, int& result, int target, int i) {
        // base case
        if (i == nums.size()) {
            if (target == 0) {
                // find a expression that can math the target value
                result++;
            }
            return;
        }    

        // do selection for operation '-'
        target += nums[i];
        backtracking(nums, result, target, i+1);
        target -= nums[i]; // remove selection

        // do selection for operation '+'
        target -= nums[i];
        backtracking(nums, result, target, i+1);
        target += nums[i];
    }
};
// @lc code=end

