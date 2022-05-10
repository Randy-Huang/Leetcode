/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0;
        int right = 0;

        int res = 0;

        while (right < s.size()) {
            char addChar = s[right++];
            window[addChar]++;

            while (window[addChar] > 1) {
                char deleteChar = s[left++];
                window[deleteChar]--;
            }

            res = max(res, (right - left));
        }

        return res;
    }
};
// @lc code=end

