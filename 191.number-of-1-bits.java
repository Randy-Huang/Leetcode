/*
 * @lc app=leetcode id=191 lang=java
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count = 0;
        for (int i = 0; i < 32; i++) {
            if (n == 0) {
                break;
            }

            count += (n & 1);
            n >>= 1;
        }

        return count;
    }
}
// @lc code=end

