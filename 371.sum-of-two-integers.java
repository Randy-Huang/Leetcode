/*
 * @lc app=leetcode id=371 lang=java
 *
 * [371] Sum of Two Integers
 */

// @lc code=start

// Reference: https://skyyen999.gitbooks.io/-leetcode-with-javascript/content/questions/371md.html
class Solution {
    public int getSum(int a, int b) {
        if (a == 0) {
            return b;
        }

        if (b == 0) {
            return a;
        }

        while (b != 0) {
            int carry = a & b;
            a ^= b;
            b = carry << 1;
        }

        return a;
    }
}
// @lc code=end

