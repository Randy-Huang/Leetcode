/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need;
        unordered_map<char, int> window;

        int left = 0;
        int right = 0;
        int valid = 0;

        // substring
        int start = 0;
        int len = INT_MAX;

        for (char c : t) { 
            need[c]++;
        }

        while (right < s.size()) {
            char addChar = s[right++];

            // if the character is our target to find and match from s
            // just add count value to window
            if (need.count(addChar)) {
                window[addChar]++;
                if (need[addChar] == window[addChar]) {
                    valid++;
                }
            }
            
            while (valid == need.size()) {
                // update our result of sub string when shirk the window 
                // if previous len is bigger than the size of current window
                // update the length 
                if (len > (right - left)) {
                    start = left;
                    len = right - left;
                }

                char deleteChar = s[left++];

                if (need.count(deleteChar)) {
                    if (need[deleteChar] == window[deleteChar]) {
                        valid--;
                    }
                    window[deleteChar]--;
                }
            }
        }

        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};
// @lc code=end

