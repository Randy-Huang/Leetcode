/*
 * @lc app=leetcode id=342 lang=java
 *
 * [342] Power of Four
 */

// @lc code=start

// Reference: Please see the solution in Leetcode:
// https://leetcode.com/problems/power-of-three/solution/

// Reference: https://www.cnblogs.com/grandyang/p/5138212.html
class Solution {
    public boolean isPowerOfFour(int n) {
        return (Math.log10(n) / Math.log10(4)) % 1 == 0; 
    }
}
// @lc code=end

