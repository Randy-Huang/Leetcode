/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int head = 0;
        int tail = s.size() - 1;
        cout << "size: " << s.size() << "\n";
        while (head < tail) {
            if (!isValidChar(s[head])) {
                head++;
            } else if (!isValidChar(s[tail])) {
                tail--;
            // } else if (lowercase(s[head]) == lowercase(s[tail])) {
            } else if (tolower(s[head]) == tolower(s[tail])) {
                head++;
                tail--;
            } else {
                cout << head << " and " << tail << "\n";
                return false;
            }
        }

        return true;
    }

    char lowercase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c - 'A' + 'a';
        }

        return c;
    }

    bool isValidChar(char c) {
        if (c >= 'a' && c <= 'z') {
            return true;
        }

        if (c >= 'A' && c <= 'Z') {
            return true;
        }

        if (c >= '0' && c <= '9') {
            return true;
        }

        return false;
    }    
};
// @lc code=end

