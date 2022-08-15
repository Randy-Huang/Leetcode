/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") {
            return res;
        }

        string lettersMap[8] = {
            "abc", // 2
            "def", // 3
            "ghi", // 4
            "jkl", // 5
            "mno", // 6
            "pqrs", // 7
            "tuv", // 8
            "wxyz", // 9
        };

        queue<string> que;
        que.push("");

        for (int index = 0; index < digits.size(); index++) {
            char c = digits[index]; 
            string letters = lettersMap[c - '0' - 2]; // get the letters from digit number
            // we use -2 to map string array' offset 0 and 1
            // because our number begins from 2

            int size = que.size();
            for (int i = 0; i < size; i++) {
                string preLetters = que.front(); que.pop();
                
                for (auto letter : letters) {
                    que.push(preLetters + letter);
                }
            }
        }

        while (que.size() > 0) {
            res.push_back(que.front()); que.pop();
        }

        return res;
    }
};
// @lc code=end

