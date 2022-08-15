/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        // Solution 1: DP
        // int n = nums.size();

        // // let n as INT_MAX 
        // // because the most stesp at least n-1 stesp
        // vector<int> memo(n - 1,  n);
        // return dp(nums, memo, 0);

        // Solution 2: greedy
        return greedy(nums);
    }

    // dp definition
    // we want to go the final pos from current pos
    // needs steps dp(nums, memo, pos);
    int dp(vector<int>& nums, vector<int>& memo, int pos) {
        int n = nums.size();

        // base case
        if (pos >= n - 1) {
            return 0;
        }

        if (memo[pos] != n) {
            return memo[pos];
        }

        int steps = nums[pos];
        // at least from 1 step to go
        for (int i = 1; i <= steps; i++) {
            // i + pos means the next dp pos start from last i step
            // so that we can get correct steps of related pos
            memo[pos] = min(memo[pos], dp(nums, memo, i + pos) + 1);
        }

        return memo[pos];
    }

    // Think carefully about what steps we need to jump?
    // and do we need to jump every pos to jump?
    // or just choose the next most steps from current pos
    // so we just need to choose the most steps to jump
    int greedy(vector<int>& nums) {
        int n = nums.size();

        int endPos = 0;
        int steps = 0; // the most fewest steps to jump 
        int furtherest = 0;
        for (int i = 0; i < n - 1; i++) {
            int last = furtherest - 1;
            furtherest = max(last, nums[i]);

            if (endPos == i) {
                steps++;

                // choose the furtherest steps adn plus it to endPos
                // as the end condition and update steps
                endPos += furtherest;
            }
        }

        return steps;
    }
};
// @lc code=end

