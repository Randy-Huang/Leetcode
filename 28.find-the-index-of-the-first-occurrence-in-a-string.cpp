/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> prefix(needle.size());
        setPrefixTable(prefix, needle);
        offset(prefix);

        int i = 0; // text (haystack)
        int j = 0; // pattern (needle)

        while (i < haystack.size()) {
            if ((j == needle.size() - 1) && (needle[j] == haystack[i])) {
                return (i - j);
            }

            if (haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = prefix[j];
                if (j == -1) { // which means there are not any match prefix
                    i++;
                    j++;
                }
            }
        }

        return -1;
    }

    void offset(vector<int>& prefix) {
        for (int i = prefix.size() - 1; i >= 0; i--) {
            if (i == 0) {
                prefix[i] = -1;
            } else {
                prefix[i] = prefix[i-1];
            }
        }
    }

    void setPrefixTable(vector<int>& prefix, string& pattern) {
        // We have 3 cases need to take care:
        // case 1. Initialize the first value in prefix table, it shuld be 0
        // case 2. when prefix[len] == prefix[i]
        // case 3. when prefix[len] != prefix[i]

        int len = 0;
        prefix[len] = 0; // case 1

        for (int i = 1; i < pattern.size(); i++) {
            // case 3
            while (len > 0 && (pattern[i] != pattern[len])) {
                len = prefix[len - 1];
            }

            // case 2
            if (pattern[i] == pattern[len]) {
                len++;
            }

            prefix[i] = len;
        }
    }
};
// @lc code=end

