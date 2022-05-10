/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start

// Reference: https://www.cnblogs.com/grandyang/p/5999050.html
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window;

        int left = 0;
        int right = 0;

        int res = 0;
        int mostFreq = 0;

        while (right < s.size()) {
            char addChar = s[right++];
            window[addChar]++;
            
            // record the most frequent number 
            mostFreq = max(mostFreq, window[addChar]);

            // if the result of a window size subtracting mostFreq
            // is bigger than k, which means we need to reduce the left
            // value to find the next condition which can make
            // the result bigger than the previous result
            while (((right - left) - mostFreq) > k ) {
                char deleteChar = s[left++];
                window[deleteChar]--;
            }

            res = max(res, (right - left));
        }

        return res;
    }
};
// @lc code=end

