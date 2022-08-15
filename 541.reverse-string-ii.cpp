/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();

        for (int i = 0; i < size; i += (2 * k)) {
            int x = i;
            int y = (i + (k-1)) < size ? (i + (k-1)) : size - 1;

            while (x <= y) {
                char tmp = s[x];
                s[x] = s[y];
                s[y] = tmp;

                x++;
                y--;
            }
        }    

        return s;
    }
};
// @lc code=end

