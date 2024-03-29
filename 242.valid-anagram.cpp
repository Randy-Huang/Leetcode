/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         } 

//         vector<int> validation(26, 0);

//         for (char c : s) {
//             validation[c - 'a']++;
//         }

//         for (char c : t) {
//             validation[c - 'a']--;
//             if (validation[c - 'a'] < 0) {
//                 return false;
//             }
//         }
        
//         return true;
//     }

// };

// 2023.08.11
// For ASCII string only
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if (s.size() != t.size()) {
//             return false;
//         }

//         vector<int> alphabet(26, 0);
//         for (auto& c : s) {
//             alphabet[c - 'a']++;
//         }

//         for (auto& c : t) {
//             int pos = c - 'a';
//             alphabet[pos]--;
//             if (alphabet[pos] < 0) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> dict;
        for (auto& c : s) {
            dict[c]++;
        }

        for (auto& c : t) {
            dict[c]--;
            if (dict[c] < 0) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

