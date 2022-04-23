import java.util.Stack;

/*
 * @lc app=leetcode id=227 lang=java
 *
 * [227] Basic Calculator II
 */

// @lc code=start
// Preference: https://leetcode-cn.com/problems/basic-calculator-ii/solution/ji-ben-ji-suan-qi-ii-by-leetcode-solutio-cm28/
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        int res = 0;
        char preSign = '+';

        // For handing every num with sign 
        // we treat all num with sign even the first num
        // with a positive sign as default 
        for (int i = 0; i < s.length(); i++) {
            //Step1: handle num first 
            char c = s.charAt(i);
            if ('0' <= c && c <= '9') {
                num = (num * 10) + (c - '0');
            }

            // Step2: besides sign and space, we must handle num in the fianl character
            //
            // Be careful, we do every operation with a preSign and current num
            // even the first num has a preSign as a positive value,
            // so we must handle the final num using (i == s.length() - 1) in the 
            // final character
            if (((c < '0') && (c != ' ')) || (i == s.length() - 1)) {
                switch (preSign) {
                    case '+': 
                    case '-':
                        int term1 = (preSign == '+') ? num : -num;
                        stack.push(term1);
                        break;
                    case '*':
                    case '/':
                        int prevNum = stack.pop();
                        int term2 = (preSign == '*') ? prevNum * num : prevNum / num;
                        stack.push(term2);
                        break;
                }

                preSign = c;
                num = 0;
            }
        }

        while (!stack.isEmpty()) {
            res += stack.pop();
        }

        return res;
    }
}
// @lc code=end

