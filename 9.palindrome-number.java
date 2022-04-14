/*
 * @lc app=leetcode id=9 lang=java
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0 || (x != 0 && (x % 10 ) == 0)) {
            return false;
        }
        
        int origin = x;
        int result = 0;
        while (origin != 0) {
            result = (result * 10) + (origin % 10);
            origin /= 10;
        }

        return result == x;
    }
}
// @lc code=end

