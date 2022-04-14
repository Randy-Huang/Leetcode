/*
 * @lc app=leetcode id=5 lang=java
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start

// Reference: https://www.baeldung.com/cs/manachers-algorithm
// Reference: https://ithelp.ithome.com.tw/articles/10271917?sc=iThomeR
// Reference: https://www.youtube.com/watch?v=XYQecbcd6_c
class Solution {
    public String longestPalindrome(String s) {
        return expandAroundCenter(s);
    }

    // Solution: expand around center
    private String expandAroundCenter(String s) {
        String res = "";
        int resLen = 0;
        // because the length of a string may have
        // odd length and even length, so we have
        // the amount of center n + (n + 1)
        for (int i = 0; i < s.length(); i++) {
            // odd length: ab|a|ba
            int left = i;
            int right = i;
            while (left >= 0 && right < s.length() && (s.charAt(left) == s.charAt(right))) {
                if (resLen < (right - left + 1)) {
                    resLen = right - left + 1;
                    res = s.substring(left, right + 1);
                }

                left--;
                right++;
            }

            // even length: aba|aba
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && (s.charAt(left) == s.charAt(right))) {
                if (resLen < (right - left + 1)) {
                    resLen = right - left + 1;
                    res = s.substring(left, right + 1);
                }

                left--;
                right++;
            }
        }

        return res;
    }
}
// @lc code=end

