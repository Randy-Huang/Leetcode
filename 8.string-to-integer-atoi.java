/*
 * @lc app=leetcode id=8 lang=java
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
    public int myAtoi(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int num = 0;
        int sign = 1;
        
        int index = 0;
        char c = s.charAt(index);
        while (index < s.length() && s.charAt(index) == ' ') {
            index++;
        }

        if (index < s.length() && (s.charAt(index) == '+' || s.charAt(index) == '-')) {
            sign = (s.charAt(index++) == '+') ? 1 : -1;
        }

        // Integer.MAX_VALUE = 2147483647 
        // Integer.MIN_VALUE = -2147483648
        // For these edge cases, we need to take the final character to check the value
        // whether it is bigger than 7
        // If (Integer.MAX_VALUE) / 10 == 214748364 and s[i] > 7
        // the string must contain a big number bigger thant MAX and MIN
        while (index < s.length() && ('0' <= s.charAt(index) && s.charAt(index) <= '9')) {
            if (num > (Integer.MAX_VALUE / 10) || (num == (Integer.MAX_VALUE / 10) && (s.charAt(index) - 0) > '7'))  {
                return (sign == -1) ? Integer.MIN_VALUE : Integer.MAX_VALUE;
            }
            num = (num * 10) + (s.charAt(index++) - '0');
        }
        

        return sign * num;
    }
}
// @lc code=end

