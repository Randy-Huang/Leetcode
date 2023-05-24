/*
 * @lc app=leetcode id=224 lang=cpp
 *
 * [224] Basic Calculator
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        return calculate(s, 0).first;
    }

    pair<int, int> calculate(string s, int start) {
        stack<int> st;

        pair<int, int> res = {0, 0};
        
        char sign = '+';
        int num = 0;
        int preNum = 0;

        for (int i = start; i < s.size(); i++) {
            char c = s[i];

            if (isDigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isDigit(c) && c != ' ') || i == s.size() - 1) {
                if (c == '(') {
                    pair<int, int> subRes = calculate(s, i + 1);
                    num = subRes.first;

                    // store a char that is end of a ')'
                    // and then we let it keep going do following 
                    // condition, the reason is that it in this round 
                    // it will not enter the sign condition because
                    // current c == '(', so it will pass in the round
                    i = subRes.second; 
                } 
               
                switch (sign) {
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

                if (c == ')') {
                    res.second = i;
                    break;
                }

                sign = c;
                num = 0;
            }
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top(); st.pop();
        }
        res.first = sum;

        return res;
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }
};
// @lc code=end

