/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
// Solution 1: Backtracking
// class Solution {
// public:
//     vector<string> res;

//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         //vector<int> memo(s.size(), -1);
        
//         unordered_set<string> wordSet;
//         for (string s1 : wordDict) {
//             wordSet.insert(s1);
//         }

//         dp(s, 0, "", wordSet);
//         return res;
//     }

//     void dp(string s, int start, string words, unordered_set<string>& wordSet/*, vector<int>& memo */) {
//         if (s.size() == start) {
//             if (!words.empty()) {
//                 res.push_back(words);
//             }
//             return;
//         }

//         for (int len = 1; (len + start) <= s.size(); len++) {
//             string prefixStr = s.substr(start, len);
//             if (wordSet.count(prefixStr)) {
//                 //printf("start: %d, len: %d, words: %s, str: %s\n", start, len, words.c_str(), prefixStr.c_str());
                
//                 if (words.empty()) {
//                     dp(s, (start + len), prefixStr, wordSet);
//                 } else {
//                     dp(s, (start + len), (words + " " + prefixStr), wordSet);
//                 }
//             }
//         }
//     }
// };

// Solution 2: DP
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, vector<string>> memo;
        unordered_set<string> wordSet(begin(wordDict), end(wordDict));

        return dp(s, 0, wordSet, memo);
    }

    vector<string> dp(string s, int start, unordered_set<string>& wordSet, unordered_map<int, vector<string>>& memo) {
        vector<string> subWords;
        if (s.size() == start) {
            subWords.push_back("");
            return subWords;
        }

        if (memo.count(start)) {
            return memo[start];
        }

        for (int len = 1; (len + start) <= s.size(); len++) {
            string prefixStr = s.substr(start, len);
            if (wordSet.count(prefixStr)) {
                //printf("start: %d, len: %d, str: %s\n", start, len, prefixStr.c_str());

                vector<string> suffixStr = dp(s, (start + len), wordSet, memo);
                for (string word : suffixStr) {
                    if (word.empty()) {
                        subWords.push_back(prefixStr);
                    } else {
                        subWords.push_back(prefixStr + " " + word);
                    }
                }
            }
        }

        memo[start] = subWords;
        return memo[start];
    }
};
// @lc code=end

