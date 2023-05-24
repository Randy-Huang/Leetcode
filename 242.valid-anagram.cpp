/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        } 

        vector<int> validation(26, 0);

        for (char c : s) {
            validation[c - 'a']++;
        }

        for (char c : t) {
            validation[c - 'a']--;
            if (validation[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }

};
// @lc code=end

