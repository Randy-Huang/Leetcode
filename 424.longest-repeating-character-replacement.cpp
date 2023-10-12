/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 */

// @lc code=start

// Reference: https://www.cnblogs.com/grandyang/p/5999050.html
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         unordered_map<char, int> window;

//         int left = 0;
//         int right = 0;

//         int res = 0;
//         int mostFreq = 0;

//         while (right < s.size()) {
//             char addChar = s[right++];
//             window[addChar]++;
            
//             // record the most frequent number 
//             mostFreq = max(mostFreq, window[addChar]);

//             // if the result of a window size subtracting mostFreq
//             // is bigger than k, which means we need to reduce the left
//             // value to find the next condition which can make
//             // the result bigger than the previous result
//             while (((right - left) - mostFreq) > k ) {
//                 char deleteChar = s[left++];
//                 window[deleteChar]--;
//             }

//             res = max(res, (right - left));
//         }

//         return res;
//     }
// };

// Solution 1: Sliding window
// class Solution {
// public:
//     int characterReplacement(string s, int k) {
//         int res = 0;

//         int right = 0;
//         int left = 0;

//         unordered_map<char,int> alphabetCount;
//         int mostFreq = 0;

//         // We can transact the meaning of the problem
//         // "Longest Repeating Character" to another meaning
//         // what's the most frequent alphabet in a sub-array 
//         // which means we need to find a sub-array that can satisfy 
//         // the equation: 
//         //      sub-array size - mostFreq <= k
//         //
//         // because the res is related to a continues of sub-array
//         // which has most frequent alphabet,so we need to scan alphabets 
//         // in this array and need to adjust its right and left ends
//         // so we can use sliding window for this problem
//         while (right < s.size()) {
//             char addChar = s[right];
//             right++;

//             alphabetCount[addChar]++;
//             mostFreq = max(mostFreq, alphabetCount[addChar]);

//             // if the result of a window size subtracting mostFreq
//             // is bigger than k, which means we need to reduce the left
//             // value to find the next condition which can make
//             // the result bigger than the previous result
//             while (((right - left) - mostFreq) > k) {
//                 char deleteChar = s[left];
//                 left++;

//                 alphabetCount[deleteChar]--;
//             }

//             // Because we've count rihgt to the next index
//             // so just calculate (right - left) without (-1)
//             int currentWindowSize = right - left;
//             res = max(res, currentWindowSize);
//         }

//         return res;
//     }
// };

// Solution 2: Sliding window + Binary search
class Solution {
public:
    int characterReplacement(string s, int k) {
        // binary search over the length of substring
        // lo contains the valid value, and hi contains the
        // invalid value
        int left = 1;
        int right = s.size() + 1;

        while (left < right) {
            // use mid value as sub-string length
            int mid = left + (right - left) / 2;

            // upper_bound
            if (hasValidSubstring(s, k, mid)) { // mid <= value
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        // length of the longest substring that satisfies
        // the given condition
        // return value should be (left - 1)
        // because we hasValidSubstring() is to finding the 
        // result of mid <= value for upper_bound() case
        // in upper_bound(), we find the first value which
        // is greater than target
        // => value > target
        // but our purpose is to find value >= target
        // so we need to let the result left - 1
        // it also can be right - 1
        return left - 1;
    }

    bool hasValidSubstring(string s, int k, int length) {
        // take a window of length `substringLength` on the given
        // string, and move it from left to right. If this window
        // satisfies the condition of a valid string, then we return
        // true
        int left = 0;
        int right = 0;

        int mostFreqCount = 0;
        unordered_map<char, int> frequentCountMap;

        while (right < s.size()) {
            // update the count of current char in the map
            char addChar = s[right];
            frequentCountMap[addChar]++;
            right++;

            // Before we reach the length of sub-string
            // we need to make sure the condition that
            // current window size - most frequent
            // char shuld be less than or equal to k
            // => current window - mostFreqCount <= k
            // otherwise, we need to narrow down 
            // the window size adding left
            mostFreqCount = max(mostFreqCount, frequentCountMap[addChar]);
            while ((right - left ) - mostFreqCount > k) {
                char deleteChar = s[left];
                frequentCountMap[deleteChar]--;
                left++;
            }


            // if the window [left, right] exceeds substringLength
            // then move the start pointer one step toward right
            int currentWinSize = right - left; 
            if (currentWinSize == length) {
                return true;
            } 
        }

        return false;
    }
};
// @lc code=end

