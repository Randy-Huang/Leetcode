/*
 * @lc app=leetcode id=66 lang=java
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 0;
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                break;
            } else {
                digits[i] = 0;
            }
        }

        if (digits[0] == 0) {
            int results[] = new int[digits.length + 1];
            results[0] = 1;
            return results;
        }

        return digits;
    }
}
// @lc code=end

