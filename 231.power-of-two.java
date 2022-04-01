/*
 * @lc app=leetcode id=231 lang=java
 *
 * [231] Power of Two
 */

// @lc code=start
// Reference: https://leetcode.com/problems/power-of-two/discuss/1638564/3-Lines-Easy-Java-Solution-with-Explanation
class Solution {
    public boolean isPowerOfTwo(int n) {
        return solution2(n);
    }

    public boolean solution1(int n) {
        if (n <= 0) {
            return false;
        }

        if ((n & (n-1)) == 0) {
            return true;
        }

        return false;
    }

    public boolean solution2(int n) {
        if (n <= 0) {
            return false;
        }

        int one = 0;
        for (int i = 0; i < 31; i++) {
            one += (n & 1);
            n >>= 1;
        }

        return one == 1;
    }
}
// @lc code=end

