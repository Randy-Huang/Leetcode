/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();

        // reverse whole string and trim space
        for (int i = 0; i < (size / 2); i++) {
            swap(s[i], s[size - 1 - i]);
        }

        // and then reverse each word 
        int start = 0;
        int end = 0;
        for (int i = 0; i < size; i++) {
            if (s[i] != ' ') {
                // find the end index of the current word
                end = i;
                while ((size > (end + 1)) && s[end + 1] != ' ') {
                    end++;
                }

                // reverse back to the origin word
                printf("i: %d, start: %d, end: %d\n", i, start, end);
                swapChars(s, start, end);

                // trim extra space only remain one for the word
                int space = i - start; // calculate the space

                // the next world should be start without space
                // use "end - space + 2" to remove all spaces
                // only remain 1 space and start the next index
                // is the beginning of the next word
                start = end - space + 2; 
                i = end + 1; 

                // for the final without space
                end -= space;
            }
        }

        s.resize(end+1);
        return s;
    }

    void swapChars(string& s, int i, int j) {
        while (j > i) {
            swap(s[i], s[j]);

            i++;
            j--;
        }
    }
};
// @lc code=end

