/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Solution 1
        int m = word1.size();
        int n = word2.size();

        vector<vector<int>> memo(m, vector<int>(n, -1));

        int lcs = dp(word1, 0, word2, 0, memo);

        // Solution 2
        // int m = word1.size();
        // int n = word2.size();
        // int lcs = interative(word1, word2);
        return m - lcs + n - lcs;
    }

    int interative(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = (s1[i-1] == s2[j-1])
                    ? dp[i-1][j-1] + 1
                    : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[m][n];
    }

    int dp(string s1, int i, string s2, int j, vector<vector<int>>& memo) {
        // base case
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = (s1[i] == s2[j])
            ? dp(s1, i+1, s2, j+1, memo) + 1
            : max(dp(s1, i+1, s2, j, memo), dp(s1, i, s2, j+1, memo));
        
        return memo[i][j];
    }
};
// @lc code=end

