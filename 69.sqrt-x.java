/*
 * @lc app=leetcode id=69 lang=java
 *
 * [69] Sqrt(x)
 */

// @lc code=start
// Reference: https://leetcode.com/problems/sqrtx/discuss/1584603/JAVA-Binary-search-100-fast-explained-with-comments
class Solution {
    public int mySqrt(int x) {
        int start = 0;
        int end = x;
        while (end >= start) {
            long mid = (start + end) / 2;
            if (mid * mid  == x) {
                return (int)mid;
            }

            if (mid * mid < x) {
                start =(int) mid + 1;
            } else {
                end = (int)mid - 1;
            }
        }

        // if we cannot find a complete integer of a root of a num
        // we just find a low bound case of a root,
        // so we choose end
        return end;
    }
}
// @lc code=end

