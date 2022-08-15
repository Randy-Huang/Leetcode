/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        unordered_map<string, bool> memo;
        return dp(memo, s, 0, p, 0);
    }

    bool dp(unordered_map<string, bool>& memo, string& s, int i, string& p, int j) {
        int m = s.size();
        int n = p.size();

        // base case
        if (j == n) {
            // if j == n, it means the pattern finished ,
            // then we need to check the input s
            // whether it has already matched 
            return i == m;
        }

        if (i == m) {
            // if i == m, it doesn't straightforward mean
            // we only can judge j == n, for example
            // s = "a", p = "ab*c*", when i is at the end of s
            // and j is not, but p still can match s

            // So the first case we can find the pair every two chars
            // if we want to use 'c*' to match empty string in s
            //
            // s = "a", p = "ab*c*"
            // when i = 1 , it is already at the end of s
            // so when j = 1, we just check these pairs
            // can do modulo with 2
            if ((n - j) % 2 != 0) {
                return false;
            }

            // the another case we need to check
            // p = "x*y*z*" pattern
            for (; j + 1 < n; j += 2) {
                if (p[j+1] != '*') {
                    return false;
                }
            }

            return true;
        }

        string key = to_string(i) + ',' + to_string(j);
        if (memo.count(key)) {
            return memo[key];
        }

        // We first consider '.' this easy case
        bool res = false;
        if (s[i] == p[j] || p[j] == '.') {
            // then judge '*' in the next char
            if ((j < (n - 1)) && p[j + 1] == '*') {
                // dp(s, i, p, j + 2) // match 0 time
                // dp(s, i + 1, p, j) // match 1 time or more times, move i (aaa), and fixed j (*a)
                res = dp(memo, s, i, p, j + 2) || dp(memo, s, i + 1, p, j);
            } else {
                res = dp(memo, s, i + 1, p, j + 1);
            }
        } else {
            // Even the current char doesn't match '.'
            // We still can match '*' after a char (it colud math 0 time)
            // for exapme 'a' == 'ab*'
            if ((j < (n - 1)) && p[j + 1] == '*') {
                res = dp(memo, s, i, p, j + 2);
            }
        }

        memo[key] = res;
        return res;
    }
};
// @lc code=end

