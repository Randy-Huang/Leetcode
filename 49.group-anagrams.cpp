/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
// Solution: hash table + sort
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mStrPos;
        vector<vector<string>> res;
        int pos = 0;
        for (auto& str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            
            if (!mStrPos.count(tmp)) {
                mStrPos[tmp] = pos++;
                res.push_back({});
            }
            
            res[mStrPos[tmp]].push_back(str);
        }

        return res;
    }
};

// Solution: hash table with alphabet count
// class Solution {
// public:
//     const static int ALPHABET_SIZE = 26;

//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> m;

//         for (auto& str : strs) {
//             // see how many char count in str
//             vector<int> count(ALPHABET_SIZE, 0);
//             for (auto& c : str) {
//                 count[c - 'a']++;
//             }

//             string tmp;
//             for (int i = 0; i < ALPHABET_SIZE; i++) {
//                 if (count[i] == 0) {
//                     continue;
//                 }
//                 // create a unique string including 
//                 // one size string with its count
//                 // for example: ate
//                 // its unique string will be "a1e1t1"
//                 tmp += string(1, i + 'a') + to_string(count[i]);
//             }

//             m[tmp].push_back(str);
//         }

//         vector<vector<string>> res;
//         for (auto it = m.begin(); it != m.end(); it++) {
//             res.push_back(it->second);
//         }

//         return res;
//     }
// };
// @lc code=end

