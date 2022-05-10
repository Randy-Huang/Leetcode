/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;

        int left = 0;
        int right = 0;
        int valid = 0;

        vector<int> res;

        for (char c : p) {
            need[c]++;
        }

        while (right < s.size()) {
            char addChar = s[right++];
        
            if (need.count(addChar)) {
                window[addChar]++;
                if (window[addChar] == need[addChar]) {
                    valid++;
                }
            }

            while ((right - left) >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
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

        return res;
    }
};
// @lc code=end

