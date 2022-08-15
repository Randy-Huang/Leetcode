/*
 * @lc app=leetcode id=371 lang=cpp
 *
 * [371] Sum of Two Integers
 */

// @lc code=start
class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;

        int carry = 0;
        int bit = 0;
        while ((a || b || carry) && (bit < 32)) {
            int a_bit = a & 1;
            int b_bit = b & 1;

            a >>= 1;
            b >>= 1;

            int res_bit = a_bit ^ b_bit ^ carry;
            carry = (a_bit && b_bit) || ((a_bit ^ b_bit) & carry);
            // carry case:
            // If there are two values are 1 in a, b, and carry
            // we can get the new carry to be 1
            //
            // a: 0 0 | 1 1 | 1 1
            // b: 0 0 | 0 0 | 1 1
            //_------------------ 
            // c: 1 0 | 1 0 | 1 0 (old)
            // ------------------
            // c: 0 0 | 1 0 | 1 1 (new)

            // printf("a_bit: %d, b_bit: %d, carry: %d, res_bit: %d\n", a_bit, b_bit, carry, res_bit);
            res |= (res_bit << bit++);
        }

        return res;
    }
};
// @lc code=end

