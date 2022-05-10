/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
        }

        return false;
    }

    string reverseVowels(string s) {
        reverseVowels(s, 0, s.size() - 1);
        return s;
    }

    void reverseVowels(string& s, int start, int end) {
        if (start >= end) {
            return;
        }

        if (isVowel(s[start]) && isVowel(s[end])) {
            swap(s[start++], s[end--]);
        } 

        reverseVowels(s, isVowel(s[start]) ? start : start + 1, isVowel(s[end]) ? end : end - 1);
    }
};
// @lc code=end

