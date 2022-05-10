/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window;
        unordered_map<char, int> need;

        int left = 0;
        int right = 0;
        int valid = 0;

        for (char c : s1) {
            need[c]++;
        }

        while (right < s2.size()) {
            char addChar = s2[right++];

            if (need.count(addChar)) {
                window[addChar]++;
                if (need[addChar] == window[addChar]) {
                    valid++;
                }
            }

            while ((right - left) >= s1.size()) {
                if (valid == need.size()) {
                    return true;
                }

                char deleteChar = s2[left++];
                if (need.count(deleteChar)) {
                    if (need[deleteChar] == window[deleteChar]) {
                        valid--;
                    }
                    window[deleteChar]--;
                }
            }
        }

        return false;
    }
};
// @lc code=end

