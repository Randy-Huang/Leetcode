/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> window;
        for (char c : s) {
            window[c]++;
        }

        int left = 0;
        int right = 0;

        int res = 0;



        while (right < s.size()) {
            char c = s[right++];
            
            window[c]++;
            if (window[c] == k) {
                res += k;
            } else if (window[c] > k) {
                res++;
            }
        }

        return res;
    }
};
// @lc code=end

