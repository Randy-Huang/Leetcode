/*
 * @lc app=leetcode id=29 lang=java
 *
 * [29] Divide Two Integers
 */

// @lc code=start
// Reference: https://knightzone.studio/2018/10/24/3944/leetcode%EF%BC%9A29-divide-two-integers/

// Reference: https://medium.com/@ChYuan/leetcode-29-divide-two-integers-%E5%BF%83%E5%BE%97-medium-91e5fccb29fa
class Solution {
    public int divide(int dividend, int divisor) {
        // 1. Check the value if is a MAX/MIN value for edge cases
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        if (divisor == 0) {
            return Integer.MAX_VALUE;
        }

        // 2. check sign
        boolean hasSign = (dividend < 0) && (divisor > 0) || (dividend > 0) && (divisor < 0);

        long dividendL = Math.abs((long)dividend);
        long divisorL = Math.abs((long)divisor);

        if (dividendL < divisorL) {
            return 0;
        }

        // 3. find the approximately digit value to the dividend
        int maxDigit = 0;
        while ((divisorL << maxDigit) <= dividendL) {
            ++maxDigit;
        }

        // 4. Short division to be approximately the quotient
        int quotient = 0;
        for (int i = maxDigit; i >= 0; i--) {
            if (dividendL < divisorL) {
                break;
            }

            long shiftValue = (divisorL << i); 
            if (shiftValue <= dividendL ) {
                quotient += (1 << i);
                dividendL -= shiftValue;
            }
        }

        return hasSign ? -quotient : quotient;
    }
}
// @lc code=end

