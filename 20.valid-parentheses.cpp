/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    // Use stack to handle Parentheses problem is good idea by LIFO sequence
    // if we meet the left parenthesis and push it to stack
    // if we meet the right parenthesis and to see 
    // if the stack has the left parenthesis to see what they can match

    bool isValid(string s) {
        stack<char> st;

        for (auto parenthesis : s) {
            if (parenthesis == '(' || parenthesis == '{' || parenthesis == '[') {
                st.push(parenthesis);
            } else {
                if (!st.empty() && (leftOf(st.top()) == parenthesis)) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }

    char leftOf(char parenthesis) {
        if (parenthesis == '(') {
            return ')';
        }

        if (parenthesis == '{') {
            return '}';
        }

        return ']';
    }
};
// @lc code=end

