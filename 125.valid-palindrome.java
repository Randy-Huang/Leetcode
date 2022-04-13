/*
 * @lc app=leetcode id=125 lang=java
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
    // Solution: use two pointers to compare each value between left and right

    public boolean isPalindrome(String s) {
        int left = 0; 
        int right = s.length() - 1;
        
        while (left < right) {
            if (!isAlphanumeric(s.charAt(left))) {
                left++;
            } else if (!isAlphanumeric(s.charAt(right))) {
                right--;
            } else if (Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))) {
                left++;
                right--;
            } else {
                return false;
            }
        }

        return true;
    }

    public boolean isAlphanumeric(Character ch) {
        if (ch >= 'a' && ch <= 'z') {
            return true;
        }

        if (ch >= 'A' && ch <= 'Z') {
            return true;
        }

        if (ch >= '0' && ch <= '9') {
            return true;
        }

        return false;
    }
}
// @lc code=end

