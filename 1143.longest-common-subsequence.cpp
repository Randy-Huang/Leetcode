/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Solution 1
        // int m = text1.size();
        // int n = text2.size();
        // vector<vector<int>> memo(m, vector<int>(n, -1));

        // return dp(text1, 0, text2, 0, memo);

        // Solution 2
        return interative(text1, text2);
    }

    int interative(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // base case
        // for (int i = 0; i <= m; i++) {
        //     dp[i][0] = 0;
        // }

        // for (int j = 0; j <= n; j++) {
        //     dp[0][j] = 0;
        // }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1]) { // string is start from 0
                    dp[i][j] = dp[i-1][j-1] + 1; 
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }


    // Calculate the LCS between s1[i...] and s2[j...]
    int dp(string s1, int i, string s2, int j, vector<vector<int>>& memo) {

        // base case for empty string
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (s1[i] == s2[j]) {  
            memo[i][j] = 1 + dp(s1, i+1, s2, j+1, memo);
            return memo[i][j];
        }

        memo[i][j] = max(
            dp(s1, i+1, s2, j, memo), 
            dp(s1, i, s2, j+1, memo)
        );

        return memo[i][j];
    }

    int getMax(int a, int b, int c) {
        return max(a, max(b, c));
    }
};
// @lc code=end

