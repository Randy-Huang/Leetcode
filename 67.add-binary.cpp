/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        printf("i: %d, j: %d\n", i, j);
        
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int a_val = (i >= 0) ? (a[i] - '0') : 0;
            int b_val = (j >= 0) ? (b[j] - '0') : 0;

            int sum = a_val + b_val + carry;
            carry = sum / 2;
            res = to_string(sum % 2) + res;
            i--; j--;
        }

        if (carry) {
            res = '1' + res;
        }

        return res;
    }
};
// @lc code=end

