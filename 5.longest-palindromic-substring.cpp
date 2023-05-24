/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res = s.substr(0, 1);

        for (int i = 1; i < s.size(); i++) {
            string s1 = palindrome(s, i);
            if (res.size() < s1.size()) {
                res = s1;
            }

            if (res.size() == s.size()) {
                break;
            }
        }

        return res;
    }

    string palindrome(string s, int center) {
        int left = center;
        int right = center;

        while (true) {
            while (0 <= (left-1) && s[left-1] == s[center]) {
                left--;
            }

            while ((right+1) < s.size() && s[right+1] == s[center]) {
                right++;
            }

            break;
        }

        while ((0 <= (left - 1) && (right + 1) < s.size()) && s[left-1] == s[right+1]) {
            left--;
            right++;
        }
        return s.substr(left, (right - left) + 1);
    }
};
// @lc code=end

