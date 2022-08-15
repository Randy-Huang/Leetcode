/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        // Solution: recursive
        // int i = word1.size();
        // int j = word2.size();
        // vector<vector<int>> memo(i, vector<int>(j, -1));

        // // we do recursive these strings from both of the ends
        // return dp(memo, word1, i - 1, word2, j - 1); 
        
        // Solution: interative
        return interative(word1, word2);
    }

    int interative(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();

        // definition:
        // word1[0..i] and word2[0..j] minDistance is  dp[i+1][j+1]
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 2, -1));

        // base case
        // we defined dp[0][0] is empty string
        for (int i = 0; i <= size1; i++) {
            dp[i][0] = i;
        }

        for (int j = 1; j <= size2; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = getMin(
                        dp[i][j-1] + 1,    // insert
                        dp[i-1][j] + 1,    // delete
                        dp[i-1][j-1] + 1   // replace
                    );
                }
            }
        }


        return dp[size1][size2];
    }

    int dp(vector<vector<int>>& memo, string word1, int i, string word2, int j) {
        // base case
        if (i == -1) {
            return j + 1;
        }

        if (j == -1) {
            return i + 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (word1[i] == word2[j]) {
            // dp(i, j) equals dp(i-1, j-1)
            memo[i][j] = dp(memo, word1, i - 1, word2, j - 1);
        } else {
            // how to use dp to express 3 operations:
            // 1. insert
            // s1 = [r, a, d, l, e] and i = 2, s1[2] = d 
            // s2 = [a, p, p, l, e] and j = 2, s2[2] = p
            // we defined the insert operation in s2, and move s2's j pointer backwards
            // s1 = [r, a, d, p, l, e] and i = 2, s1[2] = d 
            // s2 = [a, p, p, l, e] and j = 1, s2[1] = p
            //
            // the operation of dp is dp(s1, i, s2, j - 1) + 1;
            //
            // 2. delete
            // s1 = [r, a, p, p, l, e] and i = 0, s1[0] = r 
            // s2 = [a, p, p, l, e] and j = -1
            // we defined the delete operation in s1, and move s2's i pointer backwards
            // s1 = [r, a, d, p, l, e] and i = 2, s1[2] = d 
            // s2 = [a, p, p, l, e] and j = 1, s2[1] = p
            //
            // the operation of dp is dp(s1, i - 1, s2, j) + 1;
            //
            // 3. replace
            // s1 = [r, a, d, l, e] and i = 2, s1[2] = d 
            // s2 = [a, p, p, l, e] and j = 1, s2[1] = p
            // we defined the delete operation in both, and move i and j pointers backwards
            // s1 = [r, a, p, p, l, e] and i = 1, s1[1] = a 
            // s2 = [a, p, p, l, e] and j = 0, s2[0] = a
            //
            // the operation of dp is dp(s1, i - 1, s2, j) + 1;
            //
            memo[i][j] = getMin(
                dp(memo, word1, i, word2, j - 1) + 1, 
                dp(memo, word1, i - 1, word2, j) + 1,
                dp(memo, word1, i - 1, word2, j - 1) + 1
            ); 
        }

        return memo[i][j];
    }

    int getMin(int a, int b, int c) {
        return min(a, min(b, c));
    }
};
// @lc code=end

