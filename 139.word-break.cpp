/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> memo(s.size(), -1);
        unordered_set<string> wordSet;
        for (string s1 : wordDict) {
            wordSet.insert(s1);
        }

        return dp(s, 0, wordSet, memo);
    }

    bool dp(string& s, int start, unordered_set<string>& wordSet, vector<int>& memo) {
        // bese case
        if (start == s.size()) {
            return true;
        }

        // return 0 means not matched
        // return 1 means matched
        if (memo[start] != -1) {
            return memo[start] == 1;
        } 

        //printf("start: %d, memo[start]: %d\n", start, memo[start]);
        // we let len starts from 1 not 0 because
        // start index may starts from 0 so that len + start 
        // will be 0 if we set len 0, therefore, I cannot
        // get substring from s for substr(0,0)
        for (int len = 1; (start + len) <= s.size(); len++) {
            string prefixStr = s.substr(start, len);

            if (wordSet.count(prefixStr)) {
                //printf("start: %d, len: %d, str: %s\n", start, len, prefixStr.c_str());
                if (dp(s, (start + len) , wordSet, memo)) {
                    memo[start] = 1;
                    return true;
                } 
            }
        }

        memo[start] = 0;
        return false;
    }

};
// @lc code=end

