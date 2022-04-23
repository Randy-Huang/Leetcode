/*
 * @lc app=leetcode id=224 lang=java
 *
 * [224] Basic Calculator
 */

// @lc code=start
// Reference: https://www.cnblogs.com/grandyang/p/4570699.html
class Solution {
    // Solution 1: Iteration + stack
    public int calculate(String s) {
        return calculate1(s);
    }

    // Solution 1: Iteration + stack
    private int calculate1(String s) {
        Stack<Integer> stack = new Stack<Integer>();

        int sign = 1;   // 1: positive; 0: negative
        int num = 0;    // for digits
        int res = 0;    // for reuslt
        System.out.printf("String size: %d", stack.size());
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c >= '0') {
                num = (num * 10) + (c - '0');
                System.out.printf("num: %d", num);
            } else if (c == '+' || c == '-') {
                // after assigning the result of num * sign to res, needs let num to be 0
                res += num * sign;
                num = 0;
                sign = (c == '+') ? 1 : -1;
            } else if (c == '(') {
                // set res and sign to be default value after we push their value to stack
                stack.push(res);
                stack.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += num * sign;
                num = 0;
                res *= stack.pop(); // pop previous sign, for example: +/-(res)
                res += stack.pop(); // pop previous res, previous num + (res)
            }
        }

        res += num * sign;
        return res;
    }
}
// @lc code=end

