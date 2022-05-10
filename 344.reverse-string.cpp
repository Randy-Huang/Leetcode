/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverseString(s, 0, s.size() - 1);
    }

    void reverseString(vector<char>& s, int start, int end) {
        if (start >= end) {
            return ;
        }

        swap(s[start], s[end]);

        reverseString(s, start + 1, end - 1);
    }
};
// @lc code=end

