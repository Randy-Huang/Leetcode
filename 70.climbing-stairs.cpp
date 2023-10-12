/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp((n + 1), 0);
//         dp[0] = 1;
//         dp[1] = 1;

//         for (int i = 2; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp((3), 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[2] = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return (n >= 2 ? dp[2] : dp[0]);
    }
};
// @lc code=end

