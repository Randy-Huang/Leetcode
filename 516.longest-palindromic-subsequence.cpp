/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        return interative(s);
    }

     int interative(string s) {
        int n = s.size();
        vector<int>  dp(n, 1);

        for (int i = n - 2; i >= 0; i--) {
            int pre = 0;
            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = pre + 2;
                } else {
                    dp[j] = max(dp[j], dp[j-1]);
                }
                pre = temp;
            }
        }

        return dp[n-1];
     }

    int interative2dDimen(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // we defined the final result is dp[0][n-1] in the top-right side
        // i is the subsequence of left side, j is right side

        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // we iterate from bottom right side to dp[0][n-1]
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                //printf("i: %d, j: %d\n", i, j);
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};
// @lc code=end

