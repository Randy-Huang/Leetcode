/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/7404777.html
class Solution {
public:
    int countSubstrings(string s) {
        return palindromic(s);
    }

    // solution 2: dp
    int palindromic(string s) {
        int n = s.size(); 
        int res = 0;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) { // left
            for (int j = i; j < n; j++) { // right
                // we have three cases that need to check
                // for the case 1 and 2 based on condition s[i] == s[j]
                // case 1: i == j ==> they are same letter
                // case 2: j - 1 = 1 ==> they are next each other
                //
                // for the case 3, we need to consider more information
                // case 3: j-i <= 2 ==> which means there is other letter(s) between them
                // for example, a|b|a, a|xxxx|a
                // then we need to check dp[i+1][j-1] the last dp state

                dp[i][j] = (s[i] == s[j]) && ((j - i <= 2) || dp[i + 1][j - 1]);
                if (dp[i][j]) {
                    res++;
                }
            }
        }

        return res;
    }

    // solution 1: two pointers
    int twoPointers(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {

            // odd center
            res += palindromic(s, i, i);

            // even center
            res += palindromic(s, i, i + 1);
        }

        return res;
    }

    int palindromic(string s, int left, int right) {
        int count = 0;
        while (0 <= left && right < s.size() && (s[left] == s[right])) {
            left--;
            right++;
            count++;
        }

        return count;
    }
};
// @lc code=end

