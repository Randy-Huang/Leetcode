/*
 * @lc app=leetcode id=7 lang=java
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
    public int reverse(int x) {
        if (x == Integer.MAX_VALUE || x == Integer.MIN_VALUE) {
            return 0;
        }

        int posX = x;
        int res = 0;
        while (posX != 0) {
            if (Math.abs(res) > Integer.MAX_VALUE / 10) {
                return 0;
            }

            res = res * 10 + (posX % 10);
            posX = posX / 10;
        }

        return res;
    }
}
// @lc code=end

