/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        // Solution 1 
        // int m = s1.size();
        // int n = s2.size();

        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // return dp(s1, 0, s2, 0, memo);

        // Solution 2
        // return iterative(s1, s2);

        // Solution 3 - LCS
        // int m = s1.size();
        // int n = s2.size();
        // int total = 0;
        // for (int i = 0; i < m; i++) {
        //     total += s1[i];
        // }

        // for (int j = 0; j < n; j++) {
        //     total += s2[j];
        // }

        // vector<vector<int>> memo(m, vector<int>(n, -1));
        // int lcs = dpLcs(s1, 0, s2, 0, memo);
        // return total - 2 * lcs;

        // Solution 4 - LCS
        int total = 0;
        int lcs = iterativeLcs(s1, s2, total);
        return total - 2 * lcs;
    }

    int iterativeLcs(string s1, string s2, int& total) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for (int i = m - 1; i >= 0; i--) {
            total += s1[i];
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1) {
                    total += s2[j];
                }

                dp[i][j] = (s1[i] == s2[j])
                    ? dp[i+1][j+1] + s1[i]
                    : max(dp[i+1][j], dp[i][j+1]);
            }
        }

        return dp[0][0];
    }

    int dpLcs(string s1, int i, string s2, int j, vector<vector<int>>& memo) {
        if (i == s1.size() || j == s2.size()) {
            return 0;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = (s1[i] == s2[j])
            ? dpLcs(s1, i+1, s2, j+1, memo) + s1[i]
            : max(dpLcs(s1, i+1, s2, j, memo), dpLcs(s1, i, s2, j+1, memo));

        return memo[i][j];
    }

    int iterative(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // base case when one of string is empty
        for (int i = m - 1; i >= 0; i--) {
            dp[i][n] = s1[i] + dp[i+1][n]; 
        }

        for (int j = n - 1; j >= 0; j--) {
            dp[m][j] = s2[j] + dp[m][j+1];
        }

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    dp[i][j] = dp[i+1][j+1];
                } else {
                    dp[i][j] = min(
                        dp[i+1][j] + s1[i],
                        dp[i][j+1] + s2[j]
                    );
                }
            }
        }

        return dp[0][0];
    }

    int dp(string s1, int i, string s2, int j, vector<vector<int>>& memo) {
        // base case 
        int res = 0;
        if (i == s1.size()) {
            for (; j < s2.size(); j++) {
                res += s2[j];
            }

            return res;
        }

        if (j == s2.size()) {
            for (; i < s1.size(); i++) {
                res += s1[i];
            }

            return res;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        
        memo[i][j] = (s1[i] == s2[j]) 
            ? dp(s1, i+1, s2, j+1, memo)
            : min(
                dp(s1, i+1, s2, j, memo) + s1[i], 
                dp(s1, i, s2, j+1, memo) + s2[j]
            );
        
        // Why do we choose the min result between s1 and s2
        // case 1: s1, i, s2, j+1 
        // => s2[j] is not in lcs result
        // s1[a,   b,   c,   d,   e]
        //    i
        // s2[b,   d,   e]
        //    j   j+1
        //
        // case 1: s1, i+1, s2, j
        // => s1[i] is not in lcs result
        // s1[a,   b,   c,   d,   e]
        //    i   i+1
        // s2[b,   d,   e]
        //    j   

        return memo[i][j];
    }
};
// @lc code=end

