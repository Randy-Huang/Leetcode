/*
 * @lc app=leetcode id=326 lang=java
 *
 * [326] Power of Three
 */

// @lc code=start
// Reference: Please see the solution in Leetcode:
// https://leetcode.com/problems/power-of-three/solution/

// Reference: https://www.cnblogs.com/grandyang/p/5138212.html
class Solution {
    public boolean isPowerOfThree(int n) {
        // n = 3^i
        // i = log3(n)
        // i = log10(n) / log10(3)
        return (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}
// @lc code=end

