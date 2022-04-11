/*
 * @lc app=leetcode id=1362 lang=java
 *
 * [1362] Closest Divisors
 */

// @lc code=start

// Reference: https://zhuanlan.zhihu.com/p/110517674
class Solution {
    // The purpose here is to find the square of num
    public int[] closestDivisors(int num) {
        for (int i = (int) Math.sqrt(num + 2); i >= 1; i--) {
            if ((num + 1) % i == 0) {
                return new int[]{(num + 1) / i, i};
            }

            if ((num + 2) % i == 0) {
                return new int[]{(num + 2) / i, i};
            }
        }

        return new int[2];
    }
}
// @lc code=end

