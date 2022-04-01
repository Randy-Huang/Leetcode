import java.util.Stack;

/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
    public boolean isValid(String s) {
        String map = "(){}[]";
        Stack<Character> stack = new Stack<Character>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(' || c == '[' || c == '{' ) {
                stack.push(c);
            } else {
                if (!stack.isEmpty()) {
                    if (c == ')' && stack.pop() == '(') {
                        continue;
                    } else if (c == '}' && stack.pop() == '{' ) {
                        continue;
                    } else if (c == ']' && stack.pop() == '[') {
                        continue;
                    }
                } 
                return false;
            }
        }

        return stack.isEmpty();
    }
}
// @lc code=end

