/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        int size = s.size() - 1;

        int head = 0;
        int tail = size;

        while (head < tail) {
            if (s[head] != s[tail]) {
                return hasPalindrome(s, head + 1, tail) || hasPalindrome(s, head, tail- 1);
            }

            head++;         
            tail--;
        }

        return true;    
    }

    bool hasPalindrome(string s, int head, int tail) {
        while (head < tail) {
            if (s[head] != s[tail]) {
                return false;
            }

            head++;
            tail--;
        }

        return true;
    }
};
// @lc code=end

