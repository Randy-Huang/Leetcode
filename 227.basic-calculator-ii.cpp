/*
 * @lc app=leetcode id=227 lang=cpp
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int preNum = 0;
        char sign = '+';

        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isDigit(c)) {
                num = num * 10 + (c - '0');
            } 

            // if c is sign or the final digit
            // we need to push the num to stack
            if ((!isDigit(c) && c != ' ') || i == s.size() - 1) {
                switch (sign)
                {
                    case '+':
                        st.push(num);
                        break;
                    case '-':
                        st.push(-num);
                        break;
                    case '*':
                        preNum = st.top(); st.pop();
                        st.push(preNum * num);
                        break;
                    case '/':
                        preNum = st.top(); st.pop();
                        st.push(preNum / num); 
                        break;
                }

                sign = c;
                num = 0;
            }
            
        }

        int res = 0;
        while (!st.empty()) {
            res += st.top(); st.pop();
        }

        return res;
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
};
// @lc code=end

